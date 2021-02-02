#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    check_status_MainWindow();
    //QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check_status_MainWindow()
{

    QProcess proc;

    // audio volume level
    proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-audio-volume.sh");
    proc.waitForFinished();

   QString audiovolume=proc.readAllStandardOutput();
   audiovolume = audiovolume.trimmed();

    //audio mute status
    proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-audio-mute.sh");
    proc.waitForFinished();

   QString audiomute=proc.readAllStandardOutput();
   audiomute = audiomute.trimmed();
    //qDebug()<< audiomute;
    if( audiomute == "muted")
    {
        ui->toolButton_audiomute->setChecked(true);
        ui->audiovol->setText(audiomute);
    }
    else
    {
        ui->toolButton_audiomute->setChecked(false);
        ui->audiovol->setText(audiovolume);
    }

    // mic volume level
    proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-mic-volume.sh");
    proc.waitForFinished();

   QString micvolume=proc.readAllStandardOutput();
   micvolume = micvolume.trimmed();

    //mic mute status
    proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-mic-mute.sh");
    proc.waitForFinished();

   QString micmute=proc.readAllStandardOutput();
   micmute = micmute.trimmed();
    //qDebug()<< audiomute;
    if( micmute == "muted")
    {
        ui->toolButton_micmute->setChecked(true);
        ui->micvol->setText(micmute);
    }
    else
    {
        ui->toolButton_micmute->setChecked(false);
        ui->micvol->setText(micvolume);
    }

    // brightness level
    proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-brightness.sh");
    proc.waitForFinished();

   QString bright=proc.readAllStandardOutput();
   bright = bright.trimmed();
   ui->brightness->setText(bright);
   if( bright == "100%")
   {
       ui->toolButton_brightness->setChecked(true);
   }
   else
   {
       ui->toolButton_brightness->setChecked(false);
   }



       //performance mode status

            proc.start("cat", QStringList()<< "/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor");
            proc.waitForFinished();

           QString gov=proc.readAllStandardOutput();
           gov = gov.trimmed();
            //qDebug()<< gov;
            if( gov == "performance")
                ui->toolButton_performance->setChecked(true);
            else
                ui->toolButton_performance->setChecked(false);

            //batarysaver status
            if( gov == "powersave")
                ui->toolButton_powersave->setChecked(true);
            else
                ui->toolButton_powersave->setChecked(false);

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
            proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-nightmode.sh");
            proc.waitForFinished();

           QString night=proc.readAllStandardOutput();
           night = night.trimmed();
            //qDebug()<< night;
            if( night == "enabled")
                ui->toolButton_nightmode->setChecked(true);
            else if ( night == "disabled")
                ui->toolButton_nightmode->setChecked(false);

            //rotation status

            proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-rotation.sh");
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
            proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-keyboard.sh");
            proc.waitForFinished();

           QString keyboard=proc.readAllStandardOutput();
           keyboard = keyboard.trimmed();
            //qDebug()<< keyboard;
            if( keyboard == "disabled")
                ui->toolButton_keyboardoff->setChecked(true);
            else
                ui->toolButton_keyboardoff->setChecked(false);

            // touchpad off status
            proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-touchpad.sh");
            proc.waitForFinished();

           QString touchpad=proc.readAllStandardOutput();
           touchpad = touchpad.trimmed();
            //qDebug()<< touchpad;
            if( touchpad == "disabled")
                ui->toolButton_touchpadoff->setChecked(true);
            else
                ui->toolButton_touchpadoff->setChecked(false);

            // touchscreen off status
            proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-touchscreen.sh");
            proc.waitForFinished();

           QString touchscreen=proc.readAllStandardOutput();
           touchscreen = touchscreen.trimmed();
            //qDebug()<< touchscreen;
            if( touchscreen == "disabled")
                ui->toolButton_touchscreenoff->setChecked(true);
            else
                ui->toolButton_touchscreenoff->setChecked(false);
            // camera off status
            proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-camera.sh");
            proc.waitForFinished();

           QString camera=proc.readAllStandardOutput();
           camera = camera.trimmed();
            //qDebug()<< camera;
            if( camera == "disabled")
                ui->toolButton_cameraoff->setChecked(true);
            //else
                //ui->toolButton_cameraoff->setChecked(false);
            // kbd-backlight status
            proc.start("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/check-backlight.sh");
            proc.waitForFinished();

           QString kbd=proc.readAllStandardOutput();
           kbd = kbd.trimmed();
            //qDebug()<< kbd;
            if( kbd == "enabled")
                ui->toolButton_kbdbacklight->setChecked(true);
            else
                ui->toolButton_kbdbacklight->setChecked(false);



}




void MainWindow::on_toolButton_nightmode_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/nightmode-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/nightmode-off.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_toolButton_performance_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/performance.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/powersave.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_toolButton_powersave_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/powersave.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/performance.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_toolButton_flashlight_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/flashlight-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/flashlight-off.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}


void MainWindow::on_toolButton_cameraoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/camera-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/camera-off.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_toolButton_touchpadoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/touchpad-off.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/touchpad-on.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_toolButton_touchscreenoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/touchscreen-off.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/touchscreen-on.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}



void MainWindow::on_toolbutton_dpms_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("MainWindow");
    msgBox.setText("Do you want to turn display off?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
      // do something
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/dpms-off.sh");
                proc.waitForFinished();
    }//else {
      // do something else
    //}

}

void MainWindow::on_toolButton_autorotate_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/autorotate-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/autorotate-off.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_toolButton_rotateleft_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-left.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}

void MainWindow::on_toolButton_rotatenormal_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-normal.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}

void MainWindow::on_toolButton_rotateright_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-right.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}

void MainWindow::on_toolButton_rotateinvert_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/rotate-invert.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}

void MainWindow::on_toolButton_keyboardoff_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/keyboard-off.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/keyboard-on.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}


void MainWindow::on_toolButton_kbdbacklight_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/kbd-backlight-on.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/kbd-backlight-off.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_toolButton_crefresh_clicked()
{
    check_status_MainWindow();
}


void MainWindow::on_toolButton_audiomute_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/audiomute.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/audiounmute.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_pushButton_audiovolup_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/audiovolup.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}


void MainWindow::on_pushButton_audiovoldown_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/audiovoldown.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}

void MainWindow::on_toolButton_brightness_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/brightfull.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/brightdim.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_pushButton_brightup_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/brightup.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}

void MainWindow::on_pushButton_brightdown_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/brightdown.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}

void MainWindow::on_toolButton_micmute_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/micmute.sh");
                proc.waitForFinished();
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/micunmute.sh");
                proc.waitForFinished();
    }
    check_status_MainWindow();
    check_status_MainWindow();
}

void MainWindow::on_pushButton_micvolup_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/micvolup.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}

void MainWindow::on_pushButton_micvoldown_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/micvoldown.sh");
            proc.waitForFinished();
            check_status_MainWindow();
            check_status_MainWindow();
}


void MainWindow::on_toolButton_camera_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/camera.sh");
            proc.waitForFinished();
}

void MainWindow::on_toolButton_audiorecorder_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/audio-recorder.sh");
                proc.waitForFinished();
                ui->audiorecorder->setText("Stop Recording");
                ui->audiorecorder->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/stop-recorder.sh");
                proc.waitForFinished();
                ui->audiorecorder->setText("Audio Recorder");
                ui->audiorecorder->setAlignment(Qt::AlignCenter);
    }
}

void MainWindow::on_toolButton_screenshot_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/screenshot.sh");
            proc.waitForFinished();
}

void MainWindow::on_toolButton_screenrecorder_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/screen-recorder.sh");
                proc.waitForFinished();
                ui->screenrecorder->setText("Stop Recording");
                ui->screenrecorder->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/stop-recorder.sh");
                proc.waitForFinished();
                ui->screenrecorder->setText("Screen Recorder");
                ui->screenrecorder->setAlignment(Qt::AlignCenter);
    }
}

void MainWindow::on_toolButton_screencam_clicked(bool checked)
{
    if(checked) //on
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/screencam-recorder.sh");
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/toggle_always_above.sh");
                proc.waitForFinished();
                ui->screencam->setText("Stop Recording");
                ui->screencam->setAlignment(Qt::AlignCenter);
    }
    else //off
    {
        QProcess proc;
                proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/stop-recorder.sh");
                proc.waitForFinished();
                ui->screencam->setText("Screencam Recorder");
                ui->screencam->setAlignment(Qt::AlignCenter);
    }
}


void MainWindow::on_toolButton_lockscreen_clicked()
{
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/lockscreen.sh");
            proc.waitForFinished();

}

void MainWindow::on_toolButton_logout_clicked()
{
    QMessageBox msgBox;
        msgBox.setWindowTitle("MainWindow");
        msgBox.setText("Do you want to Log Out?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/logout.sh");
            proc.waitForFinished();
           }
}

void MainWindow::on_toolButton_sleep_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("MainWindow");
    msgBox.setText("Do you want to Suspend the Device?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
    proc.waitForFinished();
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/suspend.sh");
            proc.waitForFinished();
    }
}

void MainWindow::on_toolButton_poweroff_clicked()
{
    QMessageBox msgBox;
        msgBox.setWindowTitle("MainWindow");
        msgBox.setText("Do you want to Power Off The device?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/poweroff.sh");
            proc.waitForFinished();
        }
}

void MainWindow::on_toolButton_reboot_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("MainWindow");
    msgBox.setText("Do you want to Reboot The device?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/reboot.sh");
            proc.waitForFinished();
    }
}

void MainWindow::on_toolButton_hibernate_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("MainWindow");
    msgBox.setText("Do you want to Hibernate The device?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/hibernate.sh");
            proc.waitForFinished();
    }
}

void MainWindow::on_toolButton_reboottouefi_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("MainWindow");
    msgBox.setText("Do you want to reboot The device to uefi?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/reboot-to-uefi.sh");
            proc.waitForFinished();
    }
}

void MainWindow::on_toolButton_hybridsleep_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("MainWindow");
    msgBox.setText("Do you want to put The device to Hybrid sleep ?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/hybrid-sleep.sh");
            proc.waitForFinished();
    }
}

void MainWindow::on_toolButton_suspendthenhibernate_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("MainWindow");
    msgBox.setText("Do you want to put The device to Hybrid sleep ?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
    QProcess proc;
            proc.startDetached("/bin/bash", QStringList()<< "/usr/share/qwikaccess/scripts/suspend-then-hibernate.sh");
            proc.waitForFinished();
    }
}



void MainWindow::on_pushButton_restartkeyboard_clicked()
{
    QProcess proc;
            proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/restart-keyboard.sh");
            proc.waitForFinished();
}

void MainWindow::on_pushButton_restarttouchpad_clicked()
{
    QProcess proc;
            proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/restart-touchpad.sh");
            proc.waitForFinished();
}

void MainWindow::on_pushButton_restartusb_clicked()
{
    QProcess proc;
            proc.start("pkexec", QStringList()<< "/bin/bash" << "/usr/share/qwikaccess/scripts/restart-usb.sh");
            proc.waitForFinished();
}
