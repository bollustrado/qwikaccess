#include "qwikaccess.h"
#include "ui_qwikaccess.h"

qwikaccess::qwikaccess(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::qwikaccess)
{
    ui->setupUi(this);
}

qwikaccess::~qwikaccess()
{
    delete ui;
}

#include <QProcess>

void qwikaccess::on_radioButton_toggled(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("nmcli", QStringList() << "radio" << "wifi" << "on");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("nmcli", QStringList() << "radio" << "wifi" << "off");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_radioButton_2_toggled(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("rfkill", QStringList() << "unblock" << "bluetooth");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("rfkill", QStringList() << "block" << "bluetooth");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_radioButton_3_toggled(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("mmcli", QStringList() << "-m" << "0" << "--location-enable-gps-raw" << "--location-enable-gps-nmea");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("mmcli", QStringList() << "-m" << "0" << "--location-disable-gps-raw" << "--location-disable-gps-nmea");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_pushButton_clicked()
{
    this->close();
}

/* Name of the plugin */
QString qwikaccessPlugin::name()
{
    return "qwikaccess";
}

/* The plugin version */
QString qwikaccessPlugin::version()
{
    return QString(VERSION_TEXT);
}


/* The Widget hooks for menus/toolbars */
QWidget *qwikaccessPlugin::widget(QWidget *parent)
{
    return new qwikaccess(parent);
}
