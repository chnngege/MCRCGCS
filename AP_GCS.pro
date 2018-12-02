#-------------------------------------------------
#
# Project created by QtCreator 2018-09
#
#-------------------------------------------------

QT += core gui gamepad network widgets charts 3dcore 3drender 3dextras
QT += serialport webenginewidgets webchannel
QT += sql

TARGET = MCRC
TEMPLATE = app

SUBDIRS += \
    AP_GCS.pro \
    AP_GCS.pro

RESOURCES += \
    resource/images.qrc \
    resource/map.qrc

FORMS += \
    database.ui \
    flightpara.ui \
    gyroscopeview.ui \
    magview.ui \
    mainwindow.ui \
    mappoints.ui \
    serialsetting.ui \
    setpoint.ui \
    setting.ui \
    signalchoose.ui

HEADERS += \
    board/gyroscopeview.h \
    board/magview.h \
    config/toconfig.h \
    database/database.h \
    database/databasethread.h \
    map/document.h \
    map/mappoints.h \
    map/setpoint.h \
    protocol/checksum.h \
    protocol/flightpara.h \
    protocol/helper.h \
    protocol/package.h \
    protocol/setting.h \
    protocol/types.h \
    serial/packet.h \
    serial/serialsetting.h \
    serial/serialthread.h \
    waveplot/signalchoose.h \
    waveplot/wavesetting.h \
    waveplot/wavethread.h \
    mainwindow.h \
    visualization.h \
    waveview.h \
    protocol/checksum.h \
    protocol/helper.h \
    protocol/types.h

SOURCES += \
    board/gyroscopeview.cpp \
    board/magview.cpp \
    config/toconfig.cpp \
    database/database.cpp \
    database/databasethread.cpp \
    map/document.cpp \
    map/mappoints.cpp \
    map/setpoint.cpp \
    protocol/flightpara.cpp \
    protocol/package.cpp \
    protocol/setting.cpp \
    serial/serialsetting.cpp \
    serial/serialthread.cpp \
    visual3D/visualization.cpp \
    waveplot/signalchoose.cpp \
    waveplot/wavesetting.cpp \
    waveplot/wavethread.cpp \
    waveplot/waveview.cpp \
    main.cpp \
    mainwindow.cpp



