#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets>

#include "BackGroundWidget.h"


class MainWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWidget(QWidget *contentWidget, BackgroundWidget*optionPanel, QWidget *parent = nullptr);
    
    QWidget *contentWidget() const { return _content_widget; }
    BackgroundWidget*optionPanel() const { return _option_panel; }
    
    void update(QWidget *contentWidget, BackgroundWidget *optionPanel);
    void setupUi();
    
signals:
    
public slots:
    void openOptionPanel();
    void closeOptionPanel();
    
protected:
    void hideEvent(QHideEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    
private:
    QStackedLayout *_stacked_layout;
    
    QWidget *_main_widget;
    QHBoxLayout *_main_layout;
    
    QWidget *_option_widget;
    QHBoxLayout *_option_layout;
    
    QPushButton *_showOptionPanelButton;
    
    QWidget *_content_widget;
    BackgroundWidget* _option_panel;
};

#endif // MAINWIDGET_H
