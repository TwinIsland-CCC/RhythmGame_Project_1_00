QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    difficultyandspeedselectwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    musicselectwindow.cpp \
    playscene.cpp \
    protutorialwidget.cpp \
    source.cpp \
    tutorialwindow.cpp

HEADERS += \
    difficultyandspeedselectwindow.h \
    mainwindow.h \
    musicselectwindow.h \
    playscene.h \
    protutorialwidget.h \
    source.h \
    tutorialwindow.h

FORMS += \
    difficultyandspeedselectwindow.ui \
    mainwindow.ui \
    playscene.ui \
    protutorialwidget.ui \
    tutorialwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    testres/testres.qrc

DISTFILES += \
    music/Sdorica ''the  Story Unfolds'' - Hoskey, RayRay.mp3 \
    music/Sound Souler - Paradise.mp3 \
    music/UM,XYLZ - ♪.mp3
