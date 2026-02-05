#pragma once

#include "ui_SettingMenu.h"

class SettingMenu : public QDialog
{
	Q_OBJECT

public:
	SettingMenu(QWidget* parent = nullptr);
	~SettingMenu();

private:
	Ui::Dialog ui;
};