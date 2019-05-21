#-------------------------------------------------
#
# Project created by QtCreator 2019-05-14T21:50:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AgoraVideoCall
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += src

SOURCES += \
        src/controller/agora_rtc_engine.cpp \
        src/controller/opengl_renderer.cpp \
        src/main.cpp \
        src/model/video_renderer.cpp \
        src/view/central_widget.cpp \
        src/view/device_setting_dialog.cpp \
        src/view/in_room_widget.cpp \
        src/view/join_room_widget.cpp \
        src/view/main_window.cpp \
        src/view/splash_widget.cpp \
        src/view/video_setting_dialog.cpp \
        src/view/video_widget.cpp

HEADERS += \
        src/commons/definitions.h \
        src/controller/agora_rtc_engine.h \
        src/controller/opengl_renderer.h \
        src/model/video_renderer.h \
        src/model/video_setting.h \
        src/view/central_widget.h \
        src/view/device_setting_dialog.h \
        src/view/in_room_widget.h \
        src/view/join_room_widget.h \
        src/view/main_window.h \
        src/view/splash_widget.h \
        src/view/video_setting_dialog.h \
        src/view/video_widget.h

RESOURCES += \
    resource.qrc

win32: {
  INCLUDEPATH += $$PWD/lib
  LIBS += -L$$PWD/lib/ -lagora_rtc_sdk
}

macx:{
  !exists(icon.icns) {
    RAW_ICON_PATH = $$PWD/resource/icon.png
    message("generate icon.icns")
    system(mkdir $$PWD/icon.iconset)
    system(sips -z 16 16 $$RAW_ICON_PATH --out $$PWD/icon.iconset/icon_16x16.png)
    system(sips -z 32 32 $$RAW_ICON_PATH --out $$PWD/icon.iconset/icon_16x16@2x.png)
    system(sips -z 32 32 $$RAW_ICON_PATH --out $$PWD/icon.iconset/icon_32x32.png)
    system(sips -z 64 64 $$RAW_ICON_PATH --out $$PWD/icon.iconset/icon_32x32@2x.png)
    system(sips -z 64 64 $$RAW_ICON_PATH --out $$PWD/icon.iconset/icon_64x64.png)
    system(sips -z 128 128 $$RAW_ICON_PATH --out $$PWD/icon.iconset/icon_64x64@2x.png)
    system(sips -z 128 128 $$RAW_ICON_PATH --out $$PWD/icon.iconset/icon_128x128.png)
    system(iconutil -c icns icon.iconset -o icon.icns)
  }

  ICON = icon.icns

  INCLUDEPATH += $$PWD/lib/AgoraRtcEngineKit.framework/Headers

  QMAKE_LFLAGS += -F/System/Library/Frameworks
  QMAKE_LFLAGS += -F$$PWD/lib/

  LIBS += -framework AgoraRtcEngineKit
  LIBS += -framework Foundation \
       -framework CoreAudio \
       -framework CoreVideo \
       -framework CoreServices \
       -framework AppKit \
       -framework AudioToolbox \
       -framework VideoToolbox \
       -framework Accelerate \
       -framework SystemConfiguration \
       -framework AVFoundation \
       -framework CoreMedia \
       -framework CoreWLAN \
       -framework QTKit \
       -framework CoreGraphics

  LIBS += -lresolv
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

