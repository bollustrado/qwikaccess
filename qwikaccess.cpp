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
#include <QDebug>


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
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightdim.sh");
                proc.waitForFinished(400);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/brightfull.sh");
                proc.waitForFinished(400);
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



void qwikaccess::on_pushButton_dpmsoff_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/dpms-off.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_dpmson_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/dpms-on.sh");
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

void qwikaccess::on_toolButton_rotate_clicked(bool checked)
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

void qwikaccess::on_pushButton_rotatenormal_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-normal.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_rotateleft_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-left.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_rotateinvert_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-invert.sh");
            proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_rotateright_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-right.sh");
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
                    proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/autohidpi.sh");
                    proc.waitForFinished(400);
}

void qwikaccess::on_pushButton_rmautohidpi_clicked()
{
    QProcess proc;
                    proc.startDetached("pkexec", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/rmautohidpi.sh");
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
                proc.startDetached("/bin/sh", QStringList()<< "/usr/share/qwikaccess/scripts/nightmode-on.sh");
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
                proc.startDetached("/bin/sh", QStringList()<< "/bin/sh" << "/usr/share/qwikaccess/scripts/touchscreen-off.sh");
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
