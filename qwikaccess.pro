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
# CONFIG(release):DEFINES += QT_NO_DEBUG_OUTPUT

unix {
        isEmpty(PREFIX) {
                PREFIX = /usr
        }
        BINDIR = $$PREFIX/bin

	SCRIPTS_PATH = $$PREFIX/share/qwikaccess

        target.path = $$BINDIR

        desktop.path  = $$PREFIX/share/applications/
        desktop.files = "qwikaccess.desktop"

        icons.path  = /usr/share/icons/hicolor/scalable/apps/
        icons.files = qwikaccess.svg

        scripts.files = scripts

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
