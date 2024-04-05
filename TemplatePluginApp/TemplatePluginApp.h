#pragma once

#include <QtWidgets/QWidget>
#include <QLineEdit>

class TemplatePluginApp : public QWidget
{
    Q_OBJECT

public:
    explicit TemplatePluginApp(QWidget *parent = nullptr);
    void setupUi();

private:
    QLineEdit* _lineEditRequestIDScannerB = Q_NULLPTR;
    QLineEdit* _lineEditResponseIDScannerB = Q_NULLPTR;
    QLineEdit* _lineEditBoxIDScannerB = Q_NULLPTR;
    QLineEdit* _lineEditDestinationScannerB = Q_NULLPTR;
    QLineEdit* _lineEditQuantityScannerB = Q_NULLPTR;
    QLineEdit* _lineEditMessageScannerB = Q_NULLPTR;
    QLineEdit* _lineEditSuccessScannerB = Q_NULLPTR;

    QLineEdit* _lineEditRequestIDScannerC = Q_NULLPTR;
    QLineEdit* _lineEditResponseIDScannerC = Q_NULLPTR;
    QLineEdit* _lineEditBoxIDScannerC = Q_NULLPTR;
    QLineEdit* _lineEditDestinationScannerC = Q_NULLPTR;
    QLineEdit* _lineEditQuantityScannerC = Q_NULLPTR;
    QLineEdit* _lineEditMessageScannerC = Q_NULLPTR;
    QLineEdit* _lineEditSuccessScannerC = Q_NULLPTR;
};
