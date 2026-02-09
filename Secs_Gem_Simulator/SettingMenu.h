#pragma once

#include "ui_SettingMenu.h"

#include <string>

class SettingMenu : public QDialog
{
	Q_OBJECT

public:
	SettingMenu(QWidget* parent = nullptr);
	~SettingMenu();

protected:
	void showEvent(QShowEvent* event) override;

private:
	Ui::Dialog ui;
	QString rawDigits;

	void initUi();
	bool Save_Error(QString& error_log);
	bool makeFile();
	void getFileData();
	void setValue(const std::string& type, int value);

signals:

private slots:
	void onSaveClicked();
};