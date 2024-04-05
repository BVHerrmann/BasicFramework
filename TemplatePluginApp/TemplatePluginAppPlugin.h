#pragma once

//#include <QtUiPlugin/QDesignerCustomWidgetInterface>

#include <interfaces.h>
#include <plugin.h>
#include <QtCore>
#include <QtWidgets>
#include "TemplatePluginApp.h"


class TemplatePluginAppPlugin : public Plugin, MainWindowInterface, PluginInterface
{
    Q_OBJECT
        Q_PLUGIN_METADATA(IID "de.Template.TemplatePluginAppPlugin")
        Q_INTERFACES(MainWindowInterface)
        Q_INTERFACES(PluginInterface)

public:
    TemplatePluginAppPlugin(QObject* parent = 0);
    virtual ~TemplatePluginAppPlugin();

    // PluginWindowInterface
    const QString identifier() const override { return "TemplateApp"; }
    const QString name() const override { return tr("TemplateApp"); }
    const MachineState machineState() const override { return _current_state; }
    QThread::Priority priority() const override { return QThread::IdlePriority; }
    void SetMessage(const QString& message, QtMsgType MsgType);

    // MainWindowInterface
    const WidgetType widgetType(const int idx) const override
    {
        switch (idx) {
        case 0:
            return Application;
            break;
        default:
            return Application;
        }
    }
    const QString title(const int idx) const override
    {
        (void)idx;
        return name();
    }
    QWidget* mainWidget(const int idx) const override
    {
        switch (idx) {
        case 0:
            return _widget;
        default:
            return nullptr;
        }

    }
    virtual BackGroundWidget* optionPanel(const int idx) const override
    {
        (void)idx;
        return nullptr;
    }
    int preferredTabIndex(const int idx) const override
    {
        (void)idx;
        return INT_MAX - 10;
    }
    int requiredWidgetAccessLevel(const int idx) const override
    {
        (void)idx;
        return kAccessLevelGuest;
    }
    int mainWidgetCount() const override { return 1; }

signals:

public slots:
    // PluginInterface
    void initialize() override;
    void uninitialize() override;
    void requestMachineState(const PluginInterface::MachineState state) override { _current_state = state; }
    void reset();

private:
    PluginInterface::MachineState _current_state = Production;

    TemplatePluginApp* _widget;
};


