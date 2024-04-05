#pragma once

#include <QTabWidget>

class SecondLevelNavigationWidget  : public QTabWidget
{
	Q_OBJECT

public:
	SecondLevelNavigationWidget(QWidget *parent = nullptr);
	~SecondLevelNavigationWidget();
};
