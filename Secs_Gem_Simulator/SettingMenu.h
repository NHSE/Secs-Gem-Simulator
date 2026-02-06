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

	bool makeFile();
	void getFileData();

signals:

private slots:
	void onSaveClicked();
};