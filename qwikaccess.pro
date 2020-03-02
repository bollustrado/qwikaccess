QT       += core gui widgets
TARGET   = qwikaccess
TEMPLATE = app

VERSION  = 0.0.1

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# Build section
BUILD_PREFIX = $$(CA_BUILD_DIR)

isEmpty( BUILD_PREFIX ) {
        BUILD_PREFIX = ./build
}

MOC_DIR       = $$BUILD_PREFIX/moc-qt5
OBJECTS_DIR   = $$BUILD_PREFIX/obj-qt5
RCC_DIR	      = $$BUILD_PREFIX/qrc-qt5
UI_DIR        = $$BUILD_PREFIX/uic-qt5

# Disable Debug on Release
CONFIG(release):DEFINES += QT_NO_DEBUG_OUTPUT

unix {
        isEmpty(PREFIX) {
                PREFIX = /usr
        }
        BINDIR = $$PREFIX/bin

	SCRIPTS_PATH = $$PREFIX/share/qwikaccess/scripts

        target.path = $$BINDIR

        desktop.path  = $$PREFIX/share/applications/
        desktop.files = "qwikaccess.desktop"

        icons.path  = /usr/share/icons/hicolor/scalable/apps/
        icons.files = qwikaccess.svg

        scripts.files = scripts/airplane-on.sh scripts/airplane-off.sh scripts/audiomute.sh scripts/audiounmute.sh scripts/audiovoldown.sh scripts/audiovolup.sh scripts/audio-recorder.sh scripts/autohidpi.sh scripts/autorotate-on.sh scripts/autorotate-off.sh scripts/brightdim.sh scripts/brightfull.sh scripts/brightup.sh scripts/brightdown.sh scripts/bt-on.sh scripts/bt-off.sh scripts/camera.sh scripts/camera-on.sh scripts/camera-off.sh scripts/clear-cache.sh scripts/clear-ram.sh scripts/clear-cmos.sh scripts/dpms-on.sh scripts/dpms-off.sh scripts/flashlight-on.sh scripts/flashlight-off.sh scripts/gps-on.sh scripts/gps-off.sh scripts/hotspot-on.sh scripts/hotspot-off.sh scripts/micmute.sh scripts/micunmute.sh scripts/micvolup.sh scripts/micvoldown.sh scripts/nightmode-on.sh scripts/nightmode-off.sh scripts/performance.sh scripts/powersave.sh scripts/rotate-left.sh scripts/rotate-normal.sh scripts/rotate-right.sh scripts/rotate-invert.sh scripts/logout.sh scripts/screenshot.sh  scripts/screen-recorder.sh scripts/screencam-recorder.sh scripts/reboot.sh scripts/rmautohidpi.sh scripts/poweroff.sh scripts/suspend.sh scripts/lockscreen.sh scripts/wifi-on.sh scripts/wifi-off.sh scripts/stop-recorder.sh scripts/toggle_always_above.sh scripts/restart-wifi.sh scripts/restart-bt.sh scripts/restart-usb.sh scripts/restart-keyboard.sh scripts/restart-touchpad.sh scripts/touchpad-on.sh scripts/touchpad-off.sh scripts/touchscreen-on.sh scripts/touchscreen-off.sh scripts/reboot-to-uefi.sh scripts/hibernate.sh scripts/kbd-backlight-on.sh scripts/kbd-backlight-off.sh

        scripts.path  = $$SCRIPTS_PATH
        INSTALLS += target icons desktop scripts
}

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    qwikaccess.cpp

HEADERS += \
    qwikaccess.h

FORMS += \
    qwikaccess.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
