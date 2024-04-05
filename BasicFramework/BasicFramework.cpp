#include "BasicFramework.h"
#include <QtGui>
#include <QtWidgets>

#include "titlebarwidget.h"
#include "statusbarwidget.h"
#include "tabwidget.h"
#include "pluginscontroller.h"
#include "FirstLevelNavigationWidget.h"
#include "messagespopupdialog.h"
#include "machinestatepopupdialog.h"
#include "loginpopupdialog.h"
#include "alarmwidget.h"
#include "machinestatewidget.h"

BasicFramework::BasicFramework(QWidget *parent) : QMainWindow(parent)
{
    _pluginsController = new PluginsController(this);
    _pluginsController->loadAllPlugins();
   
    // set lowest access level as default
    _current_access_level = kAccessLevelGuest;
   
    //_pluginsController->setCurrentAccessLevel(_current_access_level, QString(""), QString(""), QString(""));
    //MainWindowInterface::setAccessLevel(this, _current_access_level, QString(""),QString(""),QString(""));
    setupUi();

    showFullScreen();
    QApplication::primaryScreen()->installEventFilter(this);
    windowHandle()->installEventFilter(this);
}

BasicFramework::~BasicFramework()
{
}

void BasicFramework::initialize()
{
    setAccessLevel(currentAccessLevel());
    updateUi();
}

bool BasicFramework::event(QEvent* event)
{
    switch (event->type()) {
    case QEvent::HoverMove:
        //if (_current_access_level > UserManagement::getInstance()->getBaseAccessLevel() && _logout_timer->interval()) {
        //    _logout_timer->start();
        //}
        break;

        // show/hide overlay
    case QEvent::WindowBlocked:
        if (_overlay) {
           _overlay->show();
        }
        break;
    case QEvent::WindowUnblocked:
        if (_overlay) {
            _overlay->hide();
        }
        break;

    default:
        break;
    }

    return QMainWindow::event(event);
}

bool BasicFramework::eventFilter(QObject* object, QEvent* event)
{
    // event filter is only active in full screen mode and forces resize/fullscreen after resolution or screen change
    // this happens for example when connecting using Remote Desktop
    if (object == QApplication::primaryScreen()) {
        if (event->type() == QEvent::ScreenChangeInternal) {
            showMaximized();
            showFullScreen();
        }
        return false;
    }
    else if (object == windowHandle()) {
        if (event->type() == QEvent::Resize) {
            QResizeEvent* resize_event = dynamic_cast<QResizeEvent*>(event);
            if (resize_event && resize_event->size() != windowHandle()->screen()->geometry().size()) {
                showMaximized();
                showFullScreen();
            }
        }
        return false;
    }
    else {
        // forward to default implementation
        return QMainWindow::eventFilter(object, event);
    }
}

void BasicFramework::setupUi()
{
    setWindowTitle(QCoreApplication::applicationName());
    setCentralWidget(new QWidget());
        
    QStackedLayout* stacked_layout = new QStackedLayout(centralWidget());
    stacked_layout->setStackingMode(QStackedLayout::StackAll);
       
    QWidget* main_widget = new QWidget();
    stacked_layout->addWidget(main_widget);

    QVBoxLayout* main_layout = new QVBoxLayout(main_widget);
    main_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->setSpacing(0);

    TitleBarWidget* titleBar = new TitleBarWidget();
    connect(titleBar, &TitleBarWidget::titleClicked, [=]() { changeToFirstApplicationWidget(); });
    connect(titleBar, &TitleBarWidget::openFirstLevelNavigationClicked, this, &BasicFramework::slotShowMenuFirstLevelNavigation);
    main_layout->addWidget(titleBar);

    _statusBar = new StatusBarWidget(this);
    connect(_statusBar, &StatusBarWidget::machineStateClicked, [=]() { if (_pluginsController) { MessagesPopupDialog m(_pluginsController, this); m.exec(); } });
    connect(_statusBar, &StatusBarWidget::changeMachineStateClicked, [=]() { if (_pluginsController) { MachineStatePopupDialog m(_pluginsController, this); m.exec(); }  });
    connect(_statusBar, &StatusBarWidget::changeProductClicked, [=]() { if (_pluginsController) { _pluginsController->showProductWindow(); } });
    connect(_statusBar, &StatusBarWidget::changeUserClicked, this, static_cast<void (BasicFramework::*)()>(&BasicFramework::openLoginDialog));
    //connect(_statusBar, &StatusBarWidget::diagStateClicked, [=]() { if (_pluginsController) { _pluginsController->resetPlugins(); } });
    main_layout->addWidget(_statusBar);

    // center
    _stackWidget = new QStackedWidget();
    _sectionWidgets[MainWindowInterface::Application] = new TabWidget();
    _stackWidget->addWidget(_sectionWidgets[MainWindowInterface::Application]);
    _sectionWidgets[MainWindowInterface::Statistics] = new TabWidget();
    _stackWidget->addWidget(_sectionWidgets[MainWindowInterface::Statistics]);
    _sectionWidgets[MainWindowInterface::Messages] = new TabWidget();
    _stackWidget->addWidget(_sectionWidgets[MainWindowInterface::Messages]);
    _sectionWidgets[MainWindowInterface::Diagnostics] = new TabWidget();
    _stackWidget->addWidget(_sectionWidgets[MainWindowInterface::Diagnostics]);
    _sectionWidgets[MainWindowInterface::Settings] = new TabWidget();
    _stackWidget->addWidget(_sectionWidgets[MainWindowInterface::Settings]);
    main_layout->addWidget(_stackWidget, 1);

    // Overlay
    _overlay = new QWidget();
    _overlay->setObjectName("overlay");
    stacked_layout->addWidget(_overlay);
    stacked_layout->setCurrentWidget(_overlay);
    _overlay->hide();

    // First Level Navigation
    _menuFirstLevelNavigation = new QWidget();
    QHBoxLayout* menu_layout = new QHBoxLayout();
    menu_layout->setContentsMargins(0, 0, 0, 0);
    menu_layout->setSpacing(0);

    QPushButton* closeMenuFirstLevelNavigationButton = new QPushButton();
    closeMenuFirstLevelNavigationButton->setObjectName("invisible");
    connect(closeMenuFirstLevelNavigationButton, &QPushButton::clicked, _menuFirstLevelNavigation, &QWidget::hide);
    menu_layout->addWidget(closeMenuFirstLevelNavigationButton);

    _firstLevelNavigation = new FirstLevelNavigationWidget();
    connect(_firstLevelNavigation, &FirstLevelNavigationWidget::buttonClicked, [=](const MainWindowInterface::WidgetType& type)
        { 
            _menuFirstLevelNavigation->hide();
            _stackWidget->setCurrentWidget(_sectionWidgets[type]); 
        });
    connect(_firstLevelNavigation, &FirstLevelNavigationWidget::takeScreenshot, this, &BasicFramework::slotTakeScreenshot);
    connect(_firstLevelNavigation, &FirstLevelNavigationWidget::quit, [=]() { terminateRequest(); });
    menu_layout->addWidget(_firstLevelNavigation);

    _menuFirstLevelNavigation->setLayout(menu_layout);
    stacked_layout->addWidget(_menuFirstLevelNavigation);
    stacked_layout->setCurrentWidget(_menuFirstLevelNavigation);
    _menuFirstLevelNavigation->hide();

    _alarmWidget = new AlarmWidget(_pluginsController->alarmDatabase()->tableModel(), this);
    //_preferences_widget = new InspectorPreferencesWidget(_pluginsController, this);
    _machineStateWidget = new MachineStateWidget(_pluginsController, this);
    connect(_pluginsController, &PluginsController::machineStateChanged, this, &BasicFramework::updateUi);
    connect(_pluginsController, &PluginsController::productNameChanged, _statusBar, &StatusBarWidget::setProduct);
    connect(_pluginsController, &PluginsController::canShowProductWindowChanged, _statusBar, &StatusBarWidget::setCanShowProductWindow);

    updateUi();
}

void BasicFramework::slotShowMenuFirstLevelNavigation()
{
    if (_menuFirstLevelNavigation) {
        _menuFirstLevelNavigation->show();
    }
}

void BasicFramework::changeToFirstApplicationWidget()
{
    auto tab = _sectionWidgets[MainWindowInterface::Application];
    tab->setCurrentIndex(0);
    _stackWidget->setCurrentWidget(tab);
}

void BasicFramework::updateUi()
{
    if (_pluginsController) {
        _statusBar->setMachineState(_pluginsController->machineState(), _pluginsController->diagState());
    }
    // cleanup tabs
    if (_pluginsController) {
        auto i = _sectionWidgets.constBegin();
        while (i != _sectionWidgets.constEnd()) {
            int before_cnt = i.value()->count();
            i.value()->updateUi(_pluginsController, i.key(), _current_access_level, currentUsername(), currentUuid(), currentCardId());
            // check if first level navigation items should be hidden
            
            int cnt = i.value()->count();
            if (before_cnt == 0 && cnt > 0) {
                _firstLevelNavigation->showButton(i.key());
            }
            else if (before_cnt > 0 && cnt == 0) {
                _firstLevelNavigation->hideButton(i.key());
                if (_stackWidget->currentWidget() == i.value()) {
                    _stackWidget->setCurrentWidget(_sectionWidgets[MainWindowInterface::Application]);
                }
            }
            ++i;
        }
    }
}

void BasicFramework::slotTakeScreenshot()
{
    _menuFirstLevelNavigation->hide();

    QPixmap screenshotPixmap = window()->grab();
    QString screenshotPath = QDir(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)).filePath(tr("Screenshot") + " " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh.mm.ss") + ".png");
    bool result = screenshotPixmap.save(screenshotPath);

    if (result) {
        //AuditTrail::message(QObject::tr("Took screenshot"));

        bool openResult = QDesktopServices::openUrl(QUrl("file://" + screenshotPath));
        if (!openResult) {
            QApplication::beep();
            qWarning() << "Failed to open screenshot with default application:" << screenshotPath;
        }
    }
    else {
        qWarning() << "Failed save screenshot to:" << screenshotPath;
    }
}

void BasicFramework::terminateRequest()
{
    //AuditTrail::message(QObject::tr("Quit Application"));

    _menuFirstLevelNavigation->hide();
    _pluginsController->setRequestedMachineState(Terminate);
    changeToFirstApplicationWidget();
}

void BasicFramework::updateMessages()
{

}

const BasicFramework::WidgetType BasicFramework::widgetType(const int idx) const
{
    switch (idx) {
    case 1:
        return Messages;
        break;
    case 3:
        return Application;
        break;
    default:
        return Settings;
    }
}

const QString BasicFramework::title(const int idx) const
{
    switch (idx) {
    case 1:
        return tr("Alarm History");
        break;
    case 2:
        return tr("User Management");
        break;
    case 3:
        return tr("Messages");
        break;
    default:
        return tr("Application");
    }
}

QWidget* BasicFramework::mainWidget(const int idx) const
{
    switch (idx) {
    case 0:
        return nullptr;// _preferences_widget;
        break;
    case 1:
        return _alarmWidget;
        break;
    case 2:
        return nullptr;//_access_control_preferences;
        break;
    case 3:
        return _machineStateWidget;
        break;
    default:
        return nullptr;
    }
}
BackgroundWidget* BasicFramework::optionPanel(const int idx) const
{
    /*switch (idx) {
    case 2: {
        return currentAccessLevel() >= kAccessLevelAdmin ? _access_control_option_panel : nullptr;
        break;
    }
    default:
        return nullptr;
    }
    */
    return nullptr;
}

int BasicFramework::preferredTabIndex(const int idx) const
{
    switch (idx) {
    case 1:
        return 100;
        break;
    case 3:
        return 0;
        break;
    default:
        return INT_MAX - mainWidgetCount() + idx;
    }
}

int BasicFramework::requiredWidgetAccessLevel(const int idx) const
{
    switch (idx) {
    case 1:
        return kAccessLevelGuest;
        break;
    case 2:
        return kAccessLevelAdmin;
        break;
    case 3:
        return _pluginsController && _pluginsController->machineState() <= Initializing ? kAccessLevelGuest : kAccessLevelNA;
        break;
    default:
        return kAccessLevelBertram;
    }
}

void BasicFramework::openLoginDialog()
{
    LoginPopupDialog m(this);
    bool ok = m.exec();
    QString password = m.password();

   /* if (ok) {
        if (UserManagement::instance().containsProperty(UserManagement::password, qHash(password))) {
            USER user = UserManagement::instance().getUserByProperty(UserManagement::password, qHash(password));
            _statusBar->setUsername(user.name);
            setAccessLevel(user.accessLevel, user.name, user.uuid, user.cardId);
            return;
        }
        else {
            BMessageBox::critical(this, tr("Invalid Password"), tr("The password you have entered is invalid!"), QMessageBox::Ok);
            _statusBar->setUsername(QString());
        }
    }
    else {
        _statusBar->setUsername(QString());
    }

    setAccessLevel(kAccessLevelGuest, "");
    */
}

void BasicFramework::setAccessLevel(int level, QString username, QString uuid, QString card_id)
{
    bool is_default_user_available = false;

  /*  if (username.isEmpty()) {
        QString password;

#ifdef Q_OS_WIN
        CHAR local[100];
        DWORD hstSize = sizeof(local);
        GetUserNameExA(NameUserPrincipal, local, &hstSize);
        password = local;
#endif

        if (!password.isEmpty() && UserManagement::instance().containsProperty(UserManagement::password, qHash(password))) {
            USER user = UserManagement::instance().getUserByProperty(UserManagement::password, qHash(password));

            int level = user.accessLevel;
            username = user.name;
            uuid = user.uuid;
            card_id = user.cardId;

            is_default_user_available = true;
        }
    }
    */

    //int _base_access_level = UserManagement::instance().getBaseAccessLevel();
    //_current_access_level = level < _base_access_level ? _base_access_level : level;

    _statusBar->setUsername(username);
    if (_pluginsController) {
        _pluginsController->setCurrentAccessLevel(_current_access_level, username, uuid, card_id);
    }

    // restart logout timer
    //if (_current_access_level > _base_access_level && _logout_timer->interval() && !is_default_user_available) {
    //    _logout_timer->start();
    //}

    bool changed = username != currentUsername();
    //if (changed && username.isEmpty()) { AuditTrail::message(QObject::tr("Logout")); }
    MainWindowInterface::setAccessLevel(this, _current_access_level, username, uuid, card_id);
    //if (changed && !username.isEmpty()) { AuditTrail::message(QObject::tr("Login")); }

    updateUi();
}

