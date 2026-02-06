#include "SettingMenu.h"
#include "SettingManager.h"
#include "SecsType.h"

#include <string>
#include <fstream>
#include <sstream>

#include <QMessageBox>
#include <QDir>
#include <QTextStream>

using namespace std;

SettingMenu::SettingMenu(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btn_Save, SIGNAL(clicked()), this, SLOT(onSaveClicked()));

	getFileData();
}

SettingMenu::~SettingMenu()
{

}

void SettingMenu::onSaveClicked()
{
	std::ofstream file("C:/.config/secs.conf", std::ios::out | std::ios::trunc);
	if (!file) return;

	file << "T3 : " << ui.tb_T3timer->toPlainText().toInt() << "\n";
	file << "T5 : " << ui.tb_T5timer->toPlainText().toInt() << "\n";
	file << "T6 : " << ui.tb_T6timer->toPlainText().toInt() << "\n";
	file << "T7 : " << ui.tb_T7timer->toPlainText().toInt() << "\n";
	file << "T8 : " << ui.tb_T8timer->toPlainText().toInt() << "\n";
	file.close();

	SettingManager::instance()->setAllTimeOut(ui.tb_T3timer->toPlainText().toInt(), ui.tb_T5timer->toPlainText().toInt(), 
		ui.tb_T6timer->toPlainText().toInt(), ui.tb_T7timer->toPlainText().toInt(), ui.tb_T8timer->toPlainText().toInt());
}

bool SettingMenu::makeFile()
{
	QDir dir("C:/.config");
	if (!dir.exists()) {
		dir.mkpath(".");
	}

	ofstream file("C:/.config/secs.conf");
	if (!file.is_open())	 return false;

	file << "T3 : 45\nT5 : 10\nT6 : 5\nT7 : 10\nT8 : 5";
	file.close();

	SettingManager::instance()->setAllTimeOut(45, 10, 5, 10, 5);
	ui.tb_T3timer->setText("45");
	ui.tb_T5timer->setText("10");
	ui.tb_T6timer->setText("5");
	ui.tb_T7timer->setText("10");
	ui.tb_T8timer->setText("5");

	return true;
}

void SettingMenu::getFileData()
{
	string line;
	ifstream file("C:/.config/secs.conf");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			istringstream iss(line);

			string timeout;
			int value;
			char colon;

			if (iss >> timeout >> colon >> value) 
			{
				if (timeout == "T3")
				{
					ui.tb_T3timer->setText(QString::number(value));
					SettingManager::instance()->setTimeOut("T3", value);
				}
				else if (timeout == "T5")
				{
					ui.tb_T5timer->setText(QString::number(value));
					SettingManager::instance()->setTimeOut("T5", value);
				}
				else if (timeout == "T6")
				{
					ui.tb_T6timer->setText(QString::number(value));
					SettingManager::instance()->setTimeOut("T6", value);
				}
				else if (timeout == "T7")
				{
					ui.tb_T7timer->setText(QString::number(value));
					SettingManager::instance()->setTimeOut("T7", value);
				}
				else
				{
					ui.tb_T8timer->setText(QString::number(value));
					SettingManager::instance()->setTimeOut("T8", value);
				}
			}
		}
	}
	else
	{
		if (!makeFile())
		{
			QMessageBox::critical(nullptr, "ERROR !!", "Can Not Make File");
		}
	}
}