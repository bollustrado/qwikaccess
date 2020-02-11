TEMPLATE = lib
TARGET = qwikaccess

QT += widgets

VERSION = 2.8.0

# Library section
unix:!macx: LIBS += -lcprime

# Disable warnings, enable threading support and c++11
CONFIG  += thread silent build_all c++11 plugin

# Build location
BUILD_PREFIX = $$(CA_BUILD_DIR)
isEmpty( BUILD_PREFIX ) {
        BUILD_PREFIX = ./build
}

MOC_DIR       = $$BUILD_PREFIX/moc-plugins/
OBJECTS_DIR   = $$BUILD_PREFIX/obj-plugins/
RCC_DIR       = $$BUILD_PREFIX/qrc-plugins/
UI_DIR        = $$BUILD_PREFIX/uic-plugins/

unix {
        isEmpty(PREFIX) {
                PREFIX = /usr
        }

        DEFINES += VERSION_TEXT=\"\\\"$${VERSION}\\\"\"

        INSTALLS += target
        target.path = $$PREFIX/lib/coreapps/plugins
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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

#//# Default rules for deployment.
#//qnx: target.path = /tmp/$${TARGET}/bin
#//else: unix:!android: target.path = /opt/$${TARGET}/bin
#//!isEmpty(target.path): INSTALLS += target
