#ifndef PLUGIN_H
#define PLUGIN_H

#include <QHash>
#include <QObject>
#include <QVariant>
#include <QtWidgets>

class Plugin : public QObject
{
    Q_OBJECT

  public:
    explicit Plugin(QObject* parent = 0);

    // CommunicationInterface
    virtual void setValue(const QString& name, const QVariant& value)
    {
        (void)name;
        (void)value;
        assert(false);
    }
    virtual void setValues(const QHash<QString, QVariant>& values)
    {
        (void)values;
        assert(false);
    }
    virtual void sendValue(const QString& name)
    {
        (void)name;
        assert(false);
    }

  public slots:
    // CommunicationInterface
    void setValue(const QObject* sender, const QString& name, const QVariant& value)
    {
        if (sender != this) {
            setValue(name, value);
        }
    }
    void setValues(const QObject* sender, const QHash<QString, QVariant>& values)
    {
        if (sender != this) {
            setValues(values);
        }
    }
    void sendValue(const QObject* sender, const QString& name)
    {
        if (sender != this) {
            sendValue(name);
        }
    }
};

#endif  // PLUGIN_H
