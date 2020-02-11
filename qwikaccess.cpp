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

void qwikaccess::on_radioButton_wifi_toggled(bool checked)
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
    QProcess proc;
        proc.startDetached("nmcli", QStringList() << "radio" << "wifi");
        proc.waitForFinished(400);

    QString f= proc.readAllStandardOutput();
        if (f == "enabled")
            qDebug()<< "enabled";
        else
            qDebug()<< "disabled";
}

void qwikaccess::on_radioButton_bluetooth_toggled(bool checked)
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

void qwikaccess::on_radioButton_gps_toggled(bool checked)
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

void qwikaccess::on_radioButton_quickhotspot_toggled(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("nmcli", QStringList() << "-s" << "dev" << "wifi" << "hotspot" << "con-name" << "QuickHotspot" << "ssid" << "QuickHotspot" << "password"
                                   << "pass123456789");
                proc.waitForFinished(400);
                ui->radioButton_quickhotspot->setText("QuickHotspot password: pass123456789");
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("nmcli", QStringList() << "con" << "down" << "QuickHotspot");
                proc.waitForFinished(400);
                ui->radioButton_quickhotspot->setText("Wifi Hotspot");
    }
}


/* Name of the plugin */
QString qwikaccessPlugin::name()
{
    return "Qwikaccess";
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
