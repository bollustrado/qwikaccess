#include "qwikaccess.h"
#include "ui_qwikaccess.h"
#include <QTimer>
#include <QProcess>
#include <QDebug>
#include <QPixmap>
#include <QTime>
qwikaccess::qwikaccess(QWidget *parent) 
    : QMainWindow(parent)
    , ui(new Ui::qwikaccess),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    init();

}

qwikaccess::~qwikaccess()
{
    delete ui;
}

void qwikaccess::init()
{
    // connections
    connect(timer, &QTimer::timeout, this, &qwikaccess::get_playing_media);
    connect(timer, &QTimer::timeout, this, &qwikaccess::check_status);

    // 1 second timer
    timer->start(1000);

    // initialization
    get_playing_media();
    check_status();


}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(2);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void qwikaccess::get_playing_media()
{
    QProcess proc;
    proc.start("playerctl", QStringList() << "metadata" << "title");
     proc.waitForFinished(400);
    QString t=proc.readAllStandardOutput();
    proc.start("playerctl", QStringList() << "status");
     proc.waitForFinished(400);
    QString s=proc.readAllStandardOutput();
    ui->title->setText(s + t);
    if( s == "Playing\n")
        ui->toolButton_play->setChecked(true);
    else
        ui->toolButton_play->setChecked(false);
    if( s == "Paused\n")
        ui->toolButton_pause->setChecked(true);
    else
        ui->toolButton_pause->setChecked(false);

}

void qwikaccess::check_status()
{

    QProcess proc;
    // audio volume level
    proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-audio-volume.sh");
    proc.waitForFinished();

   QString audiovolume=proc.readAllStandardOutput();
   audiovolume = audiovolume.trimmed();

    //audio mute status
    proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-audio-mute.sh");
    proc.waitForFinished();

   QString audiomute=proc.readAllStandardOutput();
   audiomute = audiomute.trimmed();
    //qDebug()<< audiomute;
    if( audiomute == "muted")
    {
        ui->toolButton_audiomute->setChecked(true);
        ui->audiomute->setText(audiomute);
    }
    else
    {
        ui->toolButton_audiomute->setChecked(false);
        ui->audiomute->setText(audiovolume);
    }

    // mic volume level
    proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-mic-volume.sh");
    proc.waitForFinished();

   QString micvolume=proc.readAllStandardOutput();
   micvolume = micvolume.trimmed();

    //mic mute status
    proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-mic-mute.sh");
    proc.waitForFinished();

   QString micmute=proc.readAllStandardOutput();
   micmute = micmute.trimmed();
    //qDebug()<< audiomute;
    if( micmute == "muted")
    {
        ui->toolButton_micmute->setChecked(true);
        ui->micmute->setText(micmute);
    }
    else
    {
        ui->toolButton_micmute->setChecked(false);
        ui->micmute->setText(micvolume);
    }


    //wifi status

            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-wifi.sh");
            proc.waitForFinished();

           QString wifi=proc.readAllStandardOutput();
           wifi = wifi.trimmed();
            //qDebug()<< wifi;
            //ui->wifi->setText(w);
            if( wifi == "enabled")
                ui->toolButton_wifi->setChecked(true);
            else
                ui->toolButton_wifi->setChecked(false);

            // bluetooth status
            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-bt.sh");
            proc.waitForFinished();

           QString bt=proc.readAllStandardOutput();
           bt = bt.trimmed();
            //qDebug()<< bt;
            if( bt == "enabled")
                ui->toolButton_bluetooth->setChecked(true);
            else
                ui->toolButton_bluetooth->setChecked(false);

            //airplanemode status

            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-airplane.sh");
            proc.waitForFinished();

           QString airp=proc.readAllStandardOutput();
           airp = airp.trimmed();
            if( airp == "enabled")
                ui->toolButton_airplanemode->setChecked(true);
            else
                ui->toolButton_airplanemode->setChecked(false);

            //gps
            proc.start("systemctl", QStringList()<< "is-enabled" << "geoclue");
            proc.waitForFinished();

           QString gps=proc.readAllStandardOutput();
           gps = gps.trimmed();
            //qDebug()<< gps;
            if( gps == "static")
                ui->toolButton_gps->setChecked(true);
            else
                ui->toolButton_gps->setChecked(false);

       //performance mode status

            proc.start("cat", QStringList()<< "/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor");
            proc.waitForFinished();

           QString gov=proc.readAllStandardOutput();
           gov = gov.trimmed();
            //qDebug()<< gov;
            if( gov == "performance")
                ui->toolButton_performacemode->setChecked(true);
            else
                ui->toolButton_performacemode->setChecked(false);

            //batarysaver status
            if( gov == "powersave")
                ui->toolButton_batterysaver->setChecked(true);
            else
                ui->toolButton_batterysaver->setChecked(false);

            //flashlight status

            proc.start("cat", QStringList()<< "/sys/class/leds/led:switch/brightness");
            proc.waitForFinished();

           QString flash=proc.readAllStandardOutput();
           flash = flash.trimmed();
            //qDebug()<< flash;
            if( flash == "1")
                ui->toolButton_flashlight->setChecked(true);
            else
                ui->toolButton_flashlight->setChecked(false);

            // nightmode status
            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-nightmode.sh");
            proc.waitForFinished();

           QString night=proc.readAllStandardOutput();
           night = night.trimmed();
            //qDebug()<< night;
            if( night == "enabled")
                ui->toolButton_nightmode->setChecked(true);
            else
                ui->toolButton_nightmode->setChecked(false);

            //rotation status

            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-rotation.sh");
            proc.waitForFinished();

           QString rot=proc.readAllStandardOutput();
           rot = rot.trimmed();
            //qDebug()<< rot;
            if( rot == "normal")
                ui->toolButton_rotatenormal->setChecked(true);
            else
                ui->toolButton_rotatenormal->setChecked(false);
            if( rot == "left")
                ui->toolButton_rotateleft->setChecked(true);
            else
                ui->toolButton_rotateleft->setChecked(false);
            if( rot == "right")
                ui->toolButton_rotateright->setChecked(true);
            else
                ui->toolButton_rotateright->setChecked(false);
            if( rot == "invert")
                ui->toolButton_rotateinvert->setChecked(true);
            else
                ui->toolButton_rotateinvert->setChecked(false);

            // keyboard off status
            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-keyboard.sh");
            proc.waitForFinished();

           QString keyboard=proc.readAllStandardOutput();
           keyboard = keyboard.trimmed();
            //qDebug()<< keyboard;
            if( keyboard == "disabled")
                ui->toolButton_keyboardoff->setChecked(true);
            else
                ui->toolButton_keyboardoff->setChecked(false);

            // touchpad off status
            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-touchpad.sh");
            proc.waitForFinished();

           QString touchpad=proc.readAllStandardOutput();
           touchpad = touchpad.trimmed();
            //qDebug()<< touchpad;
            if( touchpad == "disabled")
                ui->toolButton_touchpadoff->setChecked(true);
            else
                ui->toolButton_touchpadoff->setChecked(false);

            // touchscreen off status
            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-touchscreen.sh");
            proc.waitForFinished();

           QString touchscreen=proc.readAllStandardOutput();
           touchscreen = touchscreen.trimmed();
            //qDebug()<< touchscreen;
            if( touchscreen == "disabled")
                ui->toolButton_touchscreenoff->setChecked(true);
            else
                ui->toolButton_touchscreenoff->setChecked(false);
            // camera off status
            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-camera.sh");
            proc.waitForFinished();

           QString camera=proc.readAllStandardOutput();
           camera = camera.trimmed();
            //qDebug()<< camera;
            if( camera == "disabled")
                ui->toolButton_cameraoff->setChecked(true);
            else
                ui->toolButton_cameraoff->setChecked(false);
            // kbd-backlight status
            proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-backlight.sh");
            proc.waitForFinished();

           QString kbd=proc.readAllStandardOutput();
           kbd = kbd.trimmed();
            //qDebug()<< kbd;
            if( kbd == "enabled")
                ui->toolButton_kbdbacklight->setChecked(true);
            else
                ui->toolButton_kbdbacklight->setChecked(false);



}

void qwikaccess::on_toolButton_camera_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/camera.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_audiorecorder_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/audio-recorder.sh");
                proc.waitForFinished(400);
                ui->audiorecorder->setText("Stop Recording");
                ui->audiorecorder->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/stop-recorder.sh");
                proc.waitForFinished(400);
                ui->audiorecorder->setText("Audio Recorder");
                ui->audiorecorder->setAlignment(Qt::AlignCenter);
    }
}

void qwikaccess::on_toolButton_screenshot_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/screenshot.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_screenrecorder_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/screen-recorder.sh");
                proc.waitForFinished(400);
                ui->screenrecorder->setText("Stop Recording");
                ui->screenrecorder->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/stop-recorder.sh");
                proc.waitForFinished(400);
                ui->screenrecorder->setText("Screen Recorder");
                ui->screenrecorder->setAlignment(Qt::AlignCenter);
    }
}

void qwikaccess::on_toolButton_screencam_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/screencam-recorder.sh");
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/toggle_always_above.sh");
                proc.waitForFinished(400);
                ui->screencam->setText("Stop Recording");
                ui->screencam->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/stop-recorder.sh");
                proc.waitForFinished(400);
                ui->screencam->setText("Screencam Recorder");
                ui->screencam->setAlignment(Qt::AlignCenter);
    }
}

void qwikaccess::on_toolButton_audiomute_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/audiomute.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/audiounmute.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_pushButton_audiovolup_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/audiovolup.sh");
            proc.waitForFinished(400);
}


void qwikaccess::on_pushButton_audiovoldown_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/audiovoldown.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_brightness_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightfull.sh");
               // proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightdim.sh");
               // proc.waitForFinished(400);
    }
}

void qwikaccess::on_pushButton_brightup_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightup.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_brightdown_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightdown.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_micmute_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/micmute.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/micunmute.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_pushButton_micvolup_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/micvolup.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_micvoldown_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/micvoldown.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_clearram_clicked()
{
    QProcess proc;
                    proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/clear-ram.sh");
                    proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_clearcmos_clicked()
{
    QProcess proc;
                    proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/clear-cmos.sh");
                    proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_clearcache_clicked()
{
    QProcess proc;
                    proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/clear-cache.sh");
                    proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_autohidpi_clicked()
{
    QProcess proc;
                    proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/autohidpi.sh");
                    proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_rmautohidpi_clicked()
{
    QProcess proc;
                    proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rmautohidpi.sh");
                    proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_restartwifi_clicked()
{
    QProcess proc;
            proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/restart-wifi.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_restartbt_clicked()
{
    QProcess proc;
            proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/restart-bt.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_restartusb_clicked()
{
    QProcess proc;
            proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/restart-usb.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_restartkeyboard_clicked()
{
    QProcess proc;
            proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/restart-keyboard.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_restarttouchpad_clicked()
{
    QProcess proc;
            proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/restart-touchpad.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_wifi_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/wifi-on.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/wifi-off.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_quickhotspot_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/hotspot-on.sh");
                proc.waitForFinished(400);
                ui->hotspot->setText("QuickHotspot \npass123456789");
                ui->hotspot->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/hotspot-off.sh");
                proc.waitForFinished(400);
                ui->hotspot->setText("Hotspot");
    }
}

void qwikaccess::on_toolButton_bluetooth_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/bt-on.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/bt-off.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_airplanemode_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/airplane-on.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/airplane-off.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_nightmode_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/nightmode-on.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/nightmode-off.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_performacemode_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/performance.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/powersave.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_batterysaver_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/powersave.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/performance.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_flashlight_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/flashlight-on.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/flashlight-off.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_gps_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/gps-on.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/gps-off.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_cameraoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/camera-on.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/camera-off.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_touchpadoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/touchpad-off.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/touchpad-on.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_touchscreenoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/touchscreen-off.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/touchscreen-on.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_lockscreen_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/lockscreen.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_logout_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/logout.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_suspend_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/suspend.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_poweroff_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/poweroff.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_reboot_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/reboot.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_hibernate_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/hibernate.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_rebbotuefi_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/reboot-to-uefi.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_kbdbacklight_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/kbd-backlight-on.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/kbd-backlight-off.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_hybridsleep_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/hybrid-sleep.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_suspenthenhibernate_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/suspend-then-hibernate.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_displayoff_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/dpms-off.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_prev_clicked()
{
    QProcess proc;
    proc.startDetached("playerctl", QStringList()<< "previous");
}

void qwikaccess::on_toolButton_play_clicked()
{
    QProcess proc;
    proc.startDetached("playerctl", QStringList()<< "play");
}

void qwikaccess::on_toolButton_pause_clicked()
{
    QProcess proc;
    proc.startDetached("playerctl", QStringList()<< "pause");
}

void qwikaccess::on_toolButton_next_clicked()
{
    QProcess proc;
    proc.startDetached("playerctl", QStringList()<< "next");
}

void qwikaccess::on_toolButton_shuffle_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("playerctl", QStringList()<< "shuffle" << "on");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("playerctl", QStringList()<< "shuffle" << "off");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_autorotate_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/autorotate-on.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/autorotate-off.sh");
                proc.waitForFinished(400);
    }
}

void qwikaccess::on_toolButton_rotateleft_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-left.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_rotatenormal_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-normal.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_rotateright_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-right.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_rotateinvert_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-invert.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_toolButton_keyboardoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/keyboard-off.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/keyboard-on.sh");
                proc.waitForFinished(400);
    }
}
