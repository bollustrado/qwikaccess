#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QProcess>
#include <QScroller>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void check_status_MainWindow();

    void on_toolButton_nightmode_clicked(bool checked);

    void on_toolButton_powersave_clicked(bool checked);

    void on_toolButton_flashlight_clicked(bool checked);

    void on_toolButton_cameraoff_clicked(bool checked);

    void on_toolButton_touchpadoff_clicked(bool checked);

    void on_toolButton_touchscreenoff_clicked(bool checked);

    void on_toolButton_kbdbacklight_clicked(bool checked);

    void on_toolButton_autorotate_clicked(bool checked);

    void on_toolButton_rotateleft_clicked();

    void on_toolButton_rotatenormal_clicked();

    void on_toolButton_rotateright_clicked();

    void on_toolButton_rotateinvert_clicked();

    void on_toolButton_keyboardoff_clicked(bool checked);

    void on_toolButton_crefresh_clicked();

    void on_toolButton_performance_clicked(bool checked);

    void on_toolbutton_dpms_clicked();

    void on_toolButton_audiomute_clicked(bool checked);

    void on_pushButton_audiovolup_clicked();

    void on_pushButton_audiovoldown_clicked();

    void on_toolButton_micmute_clicked(bool checked);

    void on_pushButton_micvolup_clicked();

    void on_pushButton_micvoldown_clicked();

    void on_pushButton_brightup_clicked();

    void on_pushButton_brightdown_clicked();

    void on_toolButton_brightness_clicked(bool checked);

    void on_toolButton_camera_clicked();

    void on_toolButton_audiorecorder_clicked(bool checked);

    void on_toolButton_screenshot_clicked();

    void on_toolButton_screenrecorder_clicked(bool checked);

    void on_toolButton_screencam_clicked(bool checked);

    void on_toolButton_lockscreen_clicked();

    void on_toolButton_logout_clicked();

    void on_toolButton_sleep_clicked();

    void on_toolButton_hibernate_clicked();

    void on_toolButton_poweroff_clicked();

    void on_toolButton_reboot_clicked();

    void on_toolButton_reboottouefi_clicked();

    void on_toolButton_hybridsleep_clicked();

    void on_toolButton_suspendthenhibernate_clicked();

    void on_pushButton_restartkeyboard_clicked();

    void on_pushButton_restarttouchpad_clicked();

    void on_pushButton_restartusb_clicked();

    void on_toolButton_shuffle_clicked(bool checked);

    void on_toolButton_stop_clicked();

    void on_toolButton_playpause_clicked();

    void on_toolButton_prev_clicked();

    void on_toolButton_next_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
