#include "qwikaccess.h"
#include "ui_qwikaccess.h"
#include <QTimer>
#include <QProcess>
#include <QDebug>
#include <QPixmap>
#include <QTime>
#include <QScroller>
#include <QAbstractItemView>
#include <QMessageBox>
qwikaccess::qwikaccess(QWidget *parent) 
    : QMainWindow(parent)
    , ui(new Ui::qwikaccess),
    timer(new QBasicTimer)
{
    ui->setupUi(this);
    init();
  //setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  //  setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    // hide scrollbars
            //ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
            //ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            // configure gesture and add rubberband effect
            QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);
}

qwikaccess::~qwikaccess()
{
    delete ui;
}

void qwikaccess::timerEvent(QTimerEvent *tEvent)
{
    if (tEvent->timerId() == timer->timerId()) {
        get_playing_media();
        check_status();
    }
}

void qwikaccess::init()
{
    // connections
//    connect(timer, &QTimer::timeout, this, &qwikaccess::get_playing_media);
//    connect(timer, &QTimer::timeout, this, &qwikaccess::check_status);

    // 1 second timer
    timer->start(1000, this);

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
    // playerctl
    proc.start("/bin/sh", QStringList() <<"/usr/share/qwikaccess/scripts/playerctl-metadata.sh");
     proc.waitForFinished();
    QString t=proc.readAllStandardOutput();
    proc.start("playerctl", QStringList() << "status");
     proc.waitForFinished();
    QString s=proc.readAllStandardOutput();
    s = s.trimmed();
    ui->title->setText(t);
    if( s == "Playing")
    {
        ui->playpause->setText("Pause");
        ui->toolButton_playpause->setIcon(QIcon::fromTheme("media-playback-pause"));
        ui->toolButton_playpause->setChecked(true);
        ui->toolButton_stop->setChecked(false);
    }

    else if( s == "Paused")
    {
        ui->toolButton_playpause->setIcon(QIcon::fromTheme("media-playback-start"));
        ui->toolButton_playpause->setChecked(true);
        ui->playpause->setText("Play");
        ui->toolButton_stop->setChecked(false);
    }
    else if( s == "Stopped")
    {
        ui->toolButton_playpause->setIcon(QIcon::fromTheme("media-playback-start"));
        ui->toolButton_stop->setChecked(true);
        ui->toolButton_playpause->setChecked(false);
        ui->playpause->setText("Play");
    }
    else
    {
        ui->toolButton_playpause->setIcon(QIcon::fromTheme("media-playback-start"));
        ui->toolButton_playpause->setChecked(false);
        ui->toolButton_stop->setChecked(false);
        ui->playpause->setText("Play");
    }
    //get albumart
    proc.start("/bin/sh", QStringList() << "/usr/share/qwikaccess/scripts/albumart.sh");
         proc.waitForFinished();
        QString album=proc.readAllStandardOutput();
        album = album.trimmed();
        //qDebug()<< album;

    //QString url = R"(album)";
    QPixmap img(album);
    ui->albumart->setPixmap(img);

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

    // brightness level
    proc.start("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/check-brightness.sh");
    proc.waitForFinished();

   QString bright=proc.readAllStandardOutput();
   bright = bright.trimmed();
   ui->brightness->setText(bright);

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
            else if ( night == "disabled")
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
            //else
                //ui->toolButton_cameraoff->setChecked(false);
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
            proc.waitForFinished();
}

void qwikaccess::on_toolButton_audiorecorder_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/audio-recorder.sh");
                proc.waitForFinished();
                ui->audiorecorder->setText("Stop Recording");
                ui->audiorecorder->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/stop-recorder.sh");
                proc.waitForFinished();
                ui->audiorecorder->setText("Audio Recorder");
                ui->audiorecorder->setAlignment(Qt::AlignCenter);
    }
}

void qwikaccess::on_toolButton_screenshot_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/screenshot.sh");
            proc.waitForFinished();
}

void qwikaccess::on_toolButton_screenrecorder_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/screen-recorder.sh");
                proc.waitForFinished();
                ui->screenrecorder->setText("Stop Recording");
                ui->screenrecorder->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/stop-recorder.sh");
                proc.waitForFinished();
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
                proc.waitForFinished();
                ui->screencam->setText("Stop Recording");
                ui->screencam->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/stop-recorder.sh");
                proc.waitForFinished();
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
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/audiounmute.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_pushButton_audiovolup_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/audiovolup.sh");
            proc.waitForFinished();
}


void qwikaccess::on_pushButton_audiovoldown_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/audiovoldown.sh");
            proc.waitForFinished();
}

void qwikaccess::on_toolButton_brightness_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightfull.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightdim.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_pushButton_brightup_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightup.sh");
            proc.waitForFinished();
}

void qwikaccess::on_pushButton_brightdown_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightdown.sh");
            proc.waitForFinished();
}

void qwikaccess::on_toolButton_micmute_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/micmute.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/micunmute.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_pushButton_micvolup_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/micvolup.sh");
            proc.waitForFinished();
}

void qwikaccess::on_pushButton_micvoldown_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/micvoldown.sh");
            proc.waitForFinished();
}

void qwikaccess::on_pushButton_clearram_clicked()
{
    QProcess proc;
                    proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/clear-ram.sh");
                    proc.waitForFinished();
}

void qwikaccess::on_pushButton_clearcmos_clicked()
{
    QProcess proc;
                    proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/clear-cmos.sh");
                    proc.waitForFinished();
}

void qwikaccess::on_pushButton_clearcache_clicked()
{
    QProcess proc;
                    proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/clear-cache.sh");
                    proc.waitForFinished();
}

void qwikaccess::on_pushButton_autohidpi_clicked()
{
    QProcess proc;
                    proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/autohidpi.sh");
                    proc.waitForFinished();
}

void qwikaccess::on_pushButton_rmautohidpi_clicked()
{
    QProcess proc;
                    proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rmautohidpi.sh");
                    proc.waitForFinished();
}

void qwikaccess::on_toolButton_wifi_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/wifi-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/wifi-off.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_quickhotspot_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/hotspot-on.sh");
                proc.waitForFinished();
                ui->hotspot->setText("QuickHotspot \npass123456789");
                ui->hotspot->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/hotspot-off.sh");
                proc.waitForFinished();
                ui->hotspot->setText("Hotspot");
    }
}

void qwikaccess::on_toolButton_bluetooth_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/bt-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/bt-off.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_airplanemode_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/airplane-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/airplane-off.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_nightmode_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/nightmode-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/nightmode-off.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_performacemode_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/performance.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/powersave.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_batterysaver_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/powersave.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/performance.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_flashlight_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/flashlight-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/flashlight-off.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_gps_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/gps-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/gps-off.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_cameraoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/camera-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/camera-off.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_touchpadoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/touchpad-off.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/touchpad-on.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_touchscreenoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/touchscreen-off.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/touchscreen-on.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_lockscreen_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/lockscreen.sh");
            proc.waitForFinished();

}

void qwikaccess::on_toolButton_logout_clicked()
{
    QMessageBox msgBox;
        msgBox.setWindowTitle("qwikaccess");
        msgBox.setText("Do you want to Log Out?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/logout.sh");
            proc.waitForFinished();
           }
}

void qwikaccess::on_toolButton_suspend_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("qwikaccess");
    msgBox.setText("Do you want to Suspend the Device?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/suspend.sh");
            proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_poweroff_clicked()
{
    QMessageBox msgBox;
        msgBox.setWindowTitle("qwikaccess");
        msgBox.setText("Do you want to Power Off The device?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/poweroff.sh");
            proc.waitForFinished();
        }
}

void qwikaccess::on_toolButton_reboot_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("qwikaccess");
    msgBox.setText("Do you want to Reboot The device?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/reboot.sh");
            proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_hibernate_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("qwikaccess");
    msgBox.setText("Do you want to Hibernate The device?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/hibernate.sh");
            proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_rebbotuefi_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("qwikaccess");
    msgBox.setText("Do you want to Reboot To UEFI?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/reboot-to-uefi.sh");
            proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_kbdbacklight_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/kbd-backlight-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/kbd-backlight-off.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_hybridsleep_clicked()
{
    QMessageBox msgBox;
        msgBox.setWindowTitle("qwikaccess");
        msgBox.setText("Do you want to Hybrid Sleep The device?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/hybrid-sleep.sh");
            proc.waitForFinished();
        }
}

void qwikaccess::on_toolButton_suspenthenhibernate_clicked()
{
    QMessageBox msgBox;
        msgBox.setWindowTitle("qwikaccess");
        msgBox.setText("Do you want to Suspend Then Hibernate The device?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/suspend-then-hibernate.sh");
            proc.waitForFinished();
        }
}

void qwikaccess::on_toolButton_displayoff_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Qwikaccess");
    msgBox.setText("Do you want to turn display off?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
      // do something
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/dpms-off.sh");
                proc.waitForFinished();
    }//else {
      // do something else
    //}

}

void qwikaccess::on_toolButton_prev_clicked()
{
    QProcess proc;
    proc.startDetached("playerctl", QStringList()<< "previous");
}

void qwikaccess::on_toolButton_playpause_clicked()
{
    QProcess proc;
    proc.startDetached("playerctl", QStringList()<< "play-pause");
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
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("playerctl", QStringList()<< "shuffle" << "off");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_autorotate_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/autorotate-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/autorotate-off.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_rotateleft_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-left.sh");
            proc.waitForFinished();
}

void qwikaccess::on_toolButton_rotatenormal_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-normal.sh");
            proc.waitForFinished();
}

void qwikaccess::on_toolButton_rotateright_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-right.sh");
            proc.waitForFinished();
}

void qwikaccess::on_toolButton_rotateinvert_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-invert.sh");
            proc.waitForFinished();
}

void qwikaccess::on_toolButton_keyboardoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/keyboard-off.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/keyboard-on.sh");
                proc.waitForFinished();
    }
}

void qwikaccess::on_toolButton_stop_clicked()
{
    QProcess proc;
    proc.startDetached("playerctl", QStringList()<< "stop");
}
