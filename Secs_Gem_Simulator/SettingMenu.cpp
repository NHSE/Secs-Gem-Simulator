#include "SettingMenu.h"
#include "SettingManager.h"
#include "SecsType.h"

#include <fstream>
#include <sstream>

#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

using namespace std;

SettingMenu::SettingMenu(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btn_Save, SIGNAL(clicked()), this, SLOT(onSaveClicked()));

	initUi();
}

SettingMenu::~SettingMenu()
{

}

void SettingMenu::showEvent(QShowEvent* event)
{
	QDialog::showEvent(event);
	getFileData();
}

void SettingMenu::initUi()
{
	auto numberValidator =
		new QRegularExpressionValidator(QRegularExpression(R"(^[0-9]*$)"), this);

	ui.tb_T3timer->setValidator(numberValidator);
	ui.tb_T5timer->setValidator(numberValidator);
	ui.tb_T6timer->setValidator(numberValidator);
	ui.tb_T7timer->setValidator(numberValidator);
	ui.tb_T8timer->setValidator(numberValidator);
	ui.tb_Port->setValidator(numberValidator);
	ui.tb_Deviceid->setValidator(numberValidator);

	auto ipValidator =
		new QRegularExpressionValidator(QRegularExpression(R"(^[0-9.]*$)"), this);

	ui.tb_Ip->setValidator(ipValidator);

	getFileData();
}

bool SettingMenu::Save_Error(QString& error_log)
{
	if (ui.tb_T3timer->text().toInt() < 1 || ui.tb_T3timer->text().toInt() > 120)
	{
		error_log = "Time setting of T3 is invalid";
		return false;
	}
	else if (ui.tb_T5timer->text().toInt() < 1 || ui.tb_T5timer->text().toInt() > 240)
	{
		error_log = "Time setting of T5 is invalid";
		return false;
	}
	else if (ui.tb_T6timer->text().toInt() < 1 || ui.tb_T6timer->text().toInt() > 240)
	{
		error_log = "Time setting of T6 is invalid";
		return false;
	}
	else if (ui.tb_T7timer->text().toInt() < 1 || ui.tb_T7timer->text().toInt() > 240)
	{
		error_log = "Time setting of T7 is invalid";
		return false;
	}
	else if (ui.tb_T8timer->text().toInt() < 1 || ui.tb_T8timer->text().toInt() > 240)
	{
		error_log = "Time setting of T8 is invalid";
		return false;
	}

	return true;
}

void SettingMenu::onSaveClicked()
{
	QString error_log;
	if (!Save_Error(error_log))
	{
		QMessageBox::critical(nullptr, "Error !", error_log);
		return;
	}

	std::ofstream file("C:/.config/secs.conf", std::ios::out | std::ios::trunc);
	if (!file) return;

	file << "T3 : " << ui.tb_T3timer->text().toInt() << "\n";
	file << "T5 : " << ui.tb_T5timer->text().toInt() << "\n";
	file << "T6 : " << ui.tb_T6timer->text().toInt() << "\n";
	file << "T7 : " << ui.tb_T7timer->text().toInt() << "\n";
	file << "T8 : " << ui.tb_T8timer->text().toInt() << "\n";
	file << "IP : " << ui.tb_Ip->text().toStdString() << "\n";
	file << "Port : " << ui.tb_Port->text().toInt() << "\n";
	file << "DeviceID : " << ui.tb_Deviceid->text().toInt() << "\n";
	file.close();

	SettingManager::instance()->setAllTimeOut(ui.tb_T3timer->text().toInt(), ui.tb_T5timer->text().toInt(),
		ui.tb_T6timer->text().toInt(), ui.tb_T7timer->text().toInt(), ui.tb_T8timer->text().toInt());

	SettingManager::instance()->setNetWork(ui.tb_Ip->text(), ui.tb_Port->text().toInt(), ui.tb_Deviceid->text().toInt());
}

bool SettingMenu::makeFile()
{
	QDir dir("C:/.config");
	if (!dir.exists()) {
		dir.mkpath(".");
	}

	ofstream file("C:/.config/secs.conf");
	if (!file.is_open())	 return false;

	file << "T3 : 45\nT5 : 10\nT6 : 5\nT7 : 10\nT8 : 5\nIP : 127.0.0.1\nPort : 5000\nDeviceID : 10";
	file.close();

	SettingManager::instance()->setAllTimeOut(45, 10, 5, 10, 5);
	ui.tb_T3timer->setText("45");
	ui.tb_T5timer->setText("10");
	ui.tb_T6timer->setText("5");
	ui.tb_T7timer->setText("10");
	ui.tb_T8timer->setText("5");

	ui.tb_Ip->setText("127.0.0.1");
	ui.tb_Port->setText("5000");
	ui.tb_Deviceid->setText("10");
	return true;
}

void SettingMenu::setValue(const string& type, int value)
{
	if (type == "Port")
	{
		ui.tb_Port->setText(QString::number(value));
	}
	else if (type == "DeviceID")
	{
		ui.tb_Deviceid->setText(QString::number(value));
	}
	else if (type == "T3")
	{
		ui.tb_T3timer->setText(QString::number(value));
	}
	else if (type == "T5")
	{
		ui.tb_T5timer->setText(QString::number(value));
	}
	else if (type == "T6")
	{
		ui.tb_T6timer->setText(QString::number(value));
	}
	else if (type == "T7")
	{
		ui.tb_T7timer->setText(QString::number(value));
	}
	else if (type == "T8")
	{
		ui.tb_T8timer->setText(QString::number(value));
	}
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

			string type;
			char colon;

			iss >> type >> colon;

			if (type == "IP")
			{
				std::string ip;
				iss >> ip;   // "127.0.0.1"

				QString qip = QString::fromStdString(ip);
				SettingManager::instance()->SetParameter(QString::fromStdString(type), qip);

				ui.tb_Ip->setText(QString::fromStdString(ip));
			}
			else
			{
				int value;
				iss >> value;

				SettingManager::instance()->SetParameter(QString::fromStdString(type), value);

				setValue(type, value);
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