#include "TemplatePluginApp.h"
#include <QtGui>
#include <QtWidgets>

TemplatePluginApp::TemplatePluginApp(QWidget *parent)
    : QWidget(parent)
{
    setupUi();
}

void TemplatePluginApp::setupUi()
{
    int lineEditWidth = 60;
    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->setSpacing(6);
    mainLayout->setContentsMargins(11, 11, 11, 11);

    QSpacerItem* horizontalSpacerLeft = new QSpacerItem(124, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainLayout->addItem(horizontalSpacerLeft, 0, 0, 1, 1);

    QGridLayout* gridLayoutScannerBAndC = new QGridLayout();
    gridLayoutScannerBAndC->setSpacing(6);

    //Scanner B
    QGroupBox* groupBoxScannerB = new QGroupBox(this);
    QGridLayout* gridLayoutScannerB = new QGridLayout(groupBoxScannerB);
    gridLayoutScannerB->setSpacing(6);
    gridLayoutScannerB->setContentsMargins(11, 11, 11, 11);

    //ScannerB Request
    QGridLayout* gridLayoutRequestIDScannerB = new QGridLayout();
    gridLayoutRequestIDScannerB->setSpacing(6);
    QLabel* labelRequestIDScannerB = new QLabel(groupBoxScannerB);
    _lineEditRequestIDScannerB = new QLineEdit(groupBoxScannerB);
    _lineEditRequestIDScannerB->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditRequestIDScannerB->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditRequestIDScannerB->setReadOnly(true);
    gridLayoutRequestIDScannerB->addWidget(labelRequestIDScannerB, 0, 0, 1, 1);
    gridLayoutRequestIDScannerB->addWidget(_lineEditRequestIDScannerB, 0, 1, 1, 1);
    gridLayoutScannerB->addLayout(gridLayoutRequestIDScannerB, 0, 0, 1, 1);

    // ScannerB Response
    QGridLayout* gridLayoutResponseIDScannerB = new QGridLayout();
    gridLayoutResponseIDScannerB->setSpacing(6);
    QLabel* labelResponseIDScannerB = new QLabel(groupBoxScannerB);
    _lineEditResponseIDScannerB = new QLineEdit(groupBoxScannerB);
    _lineEditResponseIDScannerB->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditResponseIDScannerB->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditResponseIDScannerB->setReadOnly(true);
    gridLayoutResponseIDScannerB->addWidget(labelResponseIDScannerB, 0, 0, 1, 1);
    gridLayoutResponseIDScannerB->addWidget(_lineEditResponseIDScannerB, 0, 1, 1, 1);
    gridLayoutScannerB->addLayout(gridLayoutResponseIDScannerB, 1, 0, 1, 1);

    // ScannerB BoxID
    QGridLayout* gridLayoutBoxIDScannerB = new QGridLayout();
    gridLayoutBoxIDScannerB->setSpacing(6);
    QLabel* labelBoxIDScannerB = new QLabel(groupBoxScannerB);
    _lineEditBoxIDScannerB = new QLineEdit(groupBoxScannerB);
    _lineEditBoxIDScannerB->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditBoxIDScannerB->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditBoxIDScannerB->setReadOnly(true);
    gridLayoutBoxIDScannerB->addWidget(labelBoxIDScannerB, 0, 0, 1, 1);
    gridLayoutBoxIDScannerB->addWidget(_lineEditBoxIDScannerB, 0, 1, 1, 1);
    gridLayoutScannerB->addLayout(gridLayoutBoxIDScannerB, 2, 0, 1, 1);

    QFrame* lineSeparateScannerB = new QFrame(groupBoxScannerB);
    lineSeparateScannerB->setLineWidth(3);
    lineSeparateScannerB->setMidLineWidth(5);
    lineSeparateScannerB->setFrameShape(QFrame::HLine);
    lineSeparateScannerB->setFrameShadow(QFrame::Sunken);
    gridLayoutScannerB->addWidget(lineSeparateScannerB, 3, 0, 1, 1);

    // ScannerB Destination
    QGridLayout* gridLayoutDestinationScannerB = new QGridLayout();
    gridLayoutDestinationScannerB->setSpacing(6);
    QLabel* labelDestinationScannerB = new QLabel(groupBoxScannerB);
    _lineEditDestinationScannerB = new QLineEdit(groupBoxScannerB);
    _lineEditDestinationScannerB->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditDestinationScannerB->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditDestinationScannerB->setReadOnly(true);
    gridLayoutDestinationScannerB->addWidget(labelDestinationScannerB, 0, 0, 1, 1);
    gridLayoutDestinationScannerB->addWidget(_lineEditDestinationScannerB, 0, 1, 1, 1);
    gridLayoutScannerB->addLayout(gridLayoutDestinationScannerB, 4, 0, 1, 1);

    // ScannerB Quantity
    QGridLayout* gridLayoutQuantityScannerB = new QGridLayout();
    gridLayoutQuantityScannerB->setSpacing(6);
    QLabel* labelQuantityScannerB = new QLabel(groupBoxScannerB);
    _lineEditQuantityScannerB = new QLineEdit(groupBoxScannerB);
    _lineEditQuantityScannerB->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditQuantityScannerB->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditQuantityScannerB->setReadOnly(true);
    gridLayoutQuantityScannerB->addWidget(labelQuantityScannerB, 0, 0, 1, 1);
    gridLayoutQuantityScannerB->addWidget(_lineEditQuantityScannerB, 0, 1, 1, 1);
    gridLayoutScannerB->addLayout(gridLayoutQuantityScannerB, 5, 0, 1, 1);

    // ScannerB Success
    QGridLayout* gridLayoutSuccessScannerB = new QGridLayout();
    gridLayoutSuccessScannerB->setSpacing(6);
    QLabel* labelSuccessScannerB = new QLabel(groupBoxScannerB);
    _lineEditSuccessScannerB = new QLineEdit(groupBoxScannerB);
    _lineEditSuccessScannerB->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditSuccessScannerB->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditSuccessScannerB->setReadOnly(true);
    gridLayoutSuccessScannerB->addWidget(labelSuccessScannerB, 0, 0, 1, 1);
    gridLayoutSuccessScannerB->addWidget(_lineEditSuccessScannerB, 0, 1, 1, 1);
    gridLayoutScannerB->addLayout(gridLayoutSuccessScannerB, 6, 0, 1, 1);


    //message status/info
    _lineEditMessageScannerB = new QLineEdit(groupBoxScannerB);
    _lineEditMessageScannerB->setReadOnly(true);
    _lineEditMessageScannerB->setAlignment(Qt::AlignJustify);
    gridLayoutScannerB->addWidget(_lineEditMessageScannerB, 7, 0, 1, 1);

    gridLayoutScannerBAndC->addWidget(groupBoxScannerB, 0, 0, 1, 1);

    //Scanner C
    QGroupBox* groupBoxScannerC = new QGroupBox(this);
    QGridLayout* gridLayoutScannerC = new QGridLayout(groupBoxScannerC);
    gridLayoutScannerC->setSpacing(6);
    gridLayoutScannerC->setContentsMargins(11, 11, 11, 11);

    // ScannerC Request
    QGridLayout* gridLayoutRequestIDScannerC = new QGridLayout();
    gridLayoutRequestIDScannerC->setSpacing(6);
    QLabel* labelRequestIDScannerC = new QLabel(groupBoxScannerC);
    _lineEditRequestIDScannerC = new QLineEdit(groupBoxScannerC);
    _lineEditRequestIDScannerC->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditRequestIDScannerC->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditRequestIDScannerC->setReadOnly(true);
    gridLayoutRequestIDScannerC->addWidget(labelRequestIDScannerC, 0, 0, 1, 1);
    gridLayoutRequestIDScannerC->addWidget(_lineEditRequestIDScannerC, 0, 1, 1, 1);
    gridLayoutScannerC->addLayout(gridLayoutRequestIDScannerC, 0, 0, 1, 1);

    // ScannerC Response
    QGridLayout* gridLayoutResponseIDScannerC = new QGridLayout();
    gridLayoutResponseIDScannerC->setSpacing(6);
    QLabel* labelResponseIDScannerC = new QLabel(groupBoxScannerC);
    _lineEditResponseIDScannerC = new QLineEdit(groupBoxScannerC);
    _lineEditResponseIDScannerC->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditResponseIDScannerC->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditResponseIDScannerC->setReadOnly(true);
    gridLayoutResponseIDScannerC->addWidget(labelResponseIDScannerC, 0, 0, 1, 1);
    gridLayoutResponseIDScannerC->addWidget(_lineEditResponseIDScannerC, 0, 1, 1, 1);
    gridLayoutScannerC->addLayout(gridLayoutResponseIDScannerC, 1, 0, 1, 1);

    // ScannerC BoxID
    QGridLayout* gridLayoutBoxIdScannerC = new QGridLayout();
    gridLayoutBoxIdScannerC->setSpacing(6);
    QLabel* labelBoxIDScannerC = new QLabel(groupBoxScannerC);
    _lineEditBoxIDScannerC = new QLineEdit(groupBoxScannerC);
    _lineEditBoxIDScannerC->setMinimumSize(QSize(60, 0));
    _lineEditBoxIDScannerC->setMaximumSize(QSize(60, 16777215));
    _lineEditBoxIDScannerC->setReadOnly(true);
    gridLayoutBoxIdScannerC->addWidget(labelBoxIDScannerC, 0, 0, 1, 1);
    gridLayoutBoxIdScannerC->addWidget(_lineEditBoxIDScannerC, 0, 1, 1, 1);
    gridLayoutScannerC->addLayout(gridLayoutBoxIdScannerC, 2, 0, 1, 1);

    QFrame* lineSeparateScannerC = new QFrame(groupBoxScannerC);
    lineSeparateScannerC->setLineWidth(3);
    lineSeparateScannerC->setMidLineWidth(5);
    lineSeparateScannerC->setFrameShape(QFrame::HLine);
    lineSeparateScannerC->setFrameShadow(QFrame::Sunken);
    gridLayoutScannerC->addWidget(lineSeparateScannerC, 3, 0, 1, 1);

    // ScannerC Destination
    QGridLayout* gridLayoutDestinationScannerC = new QGridLayout();
    gridLayoutDestinationScannerC->setSpacing(6);
    QLabel* labelDestinationScannerC = new QLabel(groupBoxScannerC);
    _lineEditDestinationScannerC = new QLineEdit(groupBoxScannerC);
    _lineEditDestinationScannerC->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditDestinationScannerC->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditDestinationScannerC->setReadOnly(true);
    gridLayoutDestinationScannerC->addWidget(labelDestinationScannerC, 0, 0, 1, 1);
    gridLayoutDestinationScannerC->addWidget(_lineEditDestinationScannerC, 0, 1, 1, 1);
    gridLayoutScannerC->addLayout(gridLayoutDestinationScannerC, 4, 0, 1, 1);

    // ScannerC Quantity
    QGridLayout* gridLayoutQuantityScannerC = new QGridLayout();
    gridLayoutQuantityScannerC->setSpacing(6);
    QLabel* labelQuantityScannerC = new QLabel(groupBoxScannerC);
    _lineEditQuantityScannerC = new QLineEdit(groupBoxScannerC);
    _lineEditQuantityScannerC->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditQuantityScannerC->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditQuantityScannerC->setReadOnly(true);
    gridLayoutQuantityScannerC->addWidget(labelQuantityScannerC, 0, 0, 1, 1);
    gridLayoutQuantityScannerC->addWidget(_lineEditQuantityScannerC, 0, 1, 1, 1);
    gridLayoutScannerC->addLayout(gridLayoutQuantityScannerC, 5, 0, 1, 1);

    // ScannerB Success
    QGridLayout* gridLayoutSuccessScannerC = new QGridLayout();
    gridLayoutSuccessScannerC->setSpacing(6);
    QLabel* labelSuccessScannerC = new QLabel(groupBoxScannerC);
    _lineEditSuccessScannerC = new QLineEdit(groupBoxScannerC);
    _lineEditSuccessScannerC->setMinimumSize(QSize(lineEditWidth, 0));
    _lineEditSuccessScannerC->setMaximumSize(QSize(lineEditWidth, 16777215));
    _lineEditSuccessScannerC->setReadOnly(true);
    gridLayoutSuccessScannerC->addWidget(labelSuccessScannerC, 0, 0, 1, 1);
    gridLayoutSuccessScannerC->addWidget(_lineEditSuccessScannerC, 0, 1, 1, 1);
    gridLayoutScannerC->addLayout(gridLayoutSuccessScannerC, 6, 0, 1, 1);

    // message status/info
    _lineEditMessageScannerC = new QLineEdit(groupBoxScannerC);
    _lineEditMessageScannerC->setReadOnly(true);
    gridLayoutScannerC->addWidget(_lineEditMessageScannerC, 7, 0, 1, 1);

    gridLayoutScannerBAndC->addWidget(groupBoxScannerC, 0, 1, 1, 1);
    mainLayout->addLayout(gridLayoutScannerBAndC, 0, 1, 1, 1);
    QSpacerItem* horizontalSpacerRight = new QSpacerItem(124, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    mainLayout->addItem(horizontalSpacerRight, 0, 2, 1, 1);
    QSpacerItem* verticalSpacer = new QSpacerItem(20, 154, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addItem(verticalSpacer, 1, 1, 1, 1);

    groupBoxScannerB->setTitle(tr("Scanner B"));
    labelRequestIDScannerB->setText(tr("Request ID:"));
    labelResponseIDScannerB->setText(tr("Response ID:"));
    labelBoxIDScannerB->setText(tr("Box ID:"));
    labelDestinationScannerB->setText(tr("Response:"));
    labelQuantityScannerB->setText(tr("Quantity:"));
    labelSuccessScannerB->setText(tr("Success:"));

    groupBoxScannerC->setTitle(tr("Scanner C"));
    labelRequestIDScannerC->setText(tr("Request ID:"));
    labelResponseIDScannerC->setText(tr("Response ID:"));
    labelBoxIDScannerC->setText(tr("Box ID:"));
    labelDestinationScannerC->setText(tr("PackingIsland:"));
    labelQuantityScannerC->setText(tr("Quantity:"));
    labelSuccessScannerC->setText(tr("Success:"));
}
