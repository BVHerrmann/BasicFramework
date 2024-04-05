#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BasicFramework.h"
#include "interfaces.h"

class BackGroundWidget;
class FirstLevelNavigationWidget;
class PluginsController;
class TabWidget;
class QStackedWidget;
class StatusBarWidget;
class BasicFramework : public QMainWindow, PluginInterface, MainWindowInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_INTERFACES(MainWindowInterface)
public:
    explicit BasicFramework(QWidget *parent = nullptr);
    ~BasicFramework();
    void changeToFirstApplicationWidget();
    void setupUi();
    //void setPluginsController(PluginsController* pluginsController);
    void updateUi();
    void terminateRequest();
    void openLoginDialog();

    // PluginInterface
    const QString identifier() const override { return "GUI-Framework"; }
    const QString name() const override { return identifier(); }
    const MachineState machineState() const override { return _currentState; }
    void updateMessages() override;

    // MainWindowInterface
    const WidgetType widgetType(const int idx) const override;
    const QString title(const int idx) const override;
    QWidget* mainWidget(const int idx) const override;
    BackgroundWidget* optionPanel(const int idx) const override;
    int preferredTabIndex(const int idx) const override;
    int requiredWidgetAccessLevel(const int idx) const override;
    int mainWidgetCount() const override { return 4; }

public slots:
    void initialize() override;
    void slotShowMenuFirstLevelNavigation();
    void slotTakeScreenshot();
    void requestMachineState(const PluginInterface::MachineState state) override { _currentState = state; updateUi(); }

    bool event(QEvent* event) override;
    void setAccessLevel(int level = 0, QString username = QString(), QString uuid = QString(), QString card_id = QString());

protected:
    bool eventFilter(QObject* object, QEvent* event) override;
private:
    Ui::BasicFrameworkClass ui;
    StatusBarWidget* _statusBar = nullptr;
    QStackedWidget* _stackWidget = nullptr;
    QHash<MainWindowInterface::WidgetType, TabWidget*> _sectionWidgets;
    PluginsController* _pluginsController = nullptr;
    int _current_access_level = kAccessLevelGuest;
    QWidget* _overlay = nullptr;
    QWidget* _menuFirstLevelNavigation = nullptr;
    QWidget* _alarmWidget = nullptr;
    QWidget* _machineStateWidget = nullptr;
    FirstLevelNavigationWidget* _firstLevelNavigation = nullptr;
    PluginInterface::MachineState _currentState = Production;

   
};
