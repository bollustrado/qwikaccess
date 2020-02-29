#ifndef QWIKACCESS_H
#define QWIKACCESS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class qwikaccess; }
QT_END_NAMESPACE

class qwikaccess : public QMainWindow
{
    Q_OBJECT

public:
    qwikaccess(QWidget *parent = nullptr);
    ~qwikaccess();

private slots:

    void on_toolButton_camera_clicked();

    void on_toolButton_audiorecorder_clicked(bool checked);

    void on_toolButton_screenshot_clicked();

    void on_toolButton_screenrecorder_clicked(bool checked);

    void on_toolButton_screencam_clicked(bool checked);

    void on_toolButton_audiomute_clicked(bool checked);

    void on_pushButton_audiovolup_clicked();

    void on_pushButton_audiovoldown_clicked();

    void on_toolButton_brightness_clicked(bool checked);

    void on_pushButton_brightup_clicked();

    void on_pushButton_brightdown_clicked();

    void on_pushButton_dpmsoff_clicked();

    void on_pushButton_dpmson_clicked();

    void on_toolButton_micmute_clicked(bool checked);

    void on_pushButton_micvolup_clicked();

    void on_pushButton_micvoldown_clicked();

    void on_toolButton_rotate_clicked(bool checked);

    void on_pushButton_rotatenormal_clicked();

    void on_pushButton_rotateleft_clicked();

    void on_pushButton_rotateinvert_clicked();

    void on_pushButton_rotateright_clicked();

    void on_pushButton_clearram_clicked();

    void on_pushButton_clearcmos_clicked();

    void on_pushButton_clearcache_clicked();

    void on_pushButton_autohidpi_clicked();

    void on_pushButton_rmautohidpi_clicked();

    void on_toolButton_wifi_clicked(bool checked);

    void on_toolButton_quickhotspot_clicked(bool checked);

    void on_toolButton_bluetooth_clicked(bool checked);

    void on_toolButton_airplanemode_clicked(bool checked);

    void on_toolButton_nightmode_clicked(bool checked);

    void on_toolButton_performacemode_clicked(bool checked);

    void on_toolButton_batterysaver_clicked(bool checked);

    void on_toolButton_flashlight_clicked(bool checked);

    void on_toolButton_gps_clicked(bool checked);

    void on_toolButton_cameraoff_clicked(bool checked);

    void on_toolButton_lockscreen_clicked();

    void on_toolButton_logout_clicked();

    void on_toolButton_suspend_clicked();

    void on_toolButton_poweroff_clicked();

    void on_toolButton_reboot_clicked();

private:
    Ui::qwikaccess *ui;
};
#endif // QWIKACCESS_H
