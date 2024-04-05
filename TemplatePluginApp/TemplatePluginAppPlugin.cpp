#include "TemplatePluginApp.h"
#include "TemplatePluginAppPlugin.h"

#include <QtCore/QtPlugin>

TemplatePluginAppPlugin::TemplatePluginAppPlugin(QObject* parent) : Plugin(parent)
{
    // initialize views
    _widget = new TemplatePluginApp(NULL);
}

TemplatePluginAppPlugin::~TemplatePluginAppPlugin()
{
    _widget->deleteLater();
}

void TemplatePluginAppPlugin::initialize()
{

}

void TemplatePluginAppPlugin::uninitialize()
{

}

// Entfernt alle Textnachrichen aus dem Fenster
void TemplatePluginAppPlugin::reset()
{
    clearMessages();
}

// Anzeigen unterschiedlicher Fehlertexte enum QtMsgType { QtDebugMsg, QtWarningMsg, QtCriticalMsg, QtFatalMsg, QtInfoMsg, QtSystemMsg = QtCriticalMsg };
void TemplatePluginAppPlugin::SetMessage(const QString& message, QtMsgType MsgType)
{
    QList<PluginInterface::Message> messages;

    messages << PluginInterface::Message(256, message, MsgType);
    PluginInterface::updateMessages(messages);
}


