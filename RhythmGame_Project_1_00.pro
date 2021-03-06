QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    difficultyandspeedselectwindow.cpp \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mylabel.cpp \
    mythread.cpp \
    newroom.cpp \
    note.cpp \
    optionwindow.cpp \
    pausewindow.cpp \
    playscene.cpp \
    protutorialwidget.cpp \
    resultwidget.cpp \
    source.cpp \
    tutorialwindow.cpp

HEADERS += \
    data.h \
    difficultyandspeedselectwindow.h \
    gamewindow.h \
    mainwindow.h \
    mylabel.h \
    mythread.h \
    newroom.h \
    note.h \
    optionwindow.h \
    pausewindow.h \
    playscene.h \
    protutorialwidget.h \
    resultwidget.h \
    source.h \
    tutorialwindow.h

FORMS += \
    difficultyandspeedselectwindow.ui \
    gamewindow.ui \
    mainwindow.ui \
    newroom.ui \
    optionwindow.ui \
    pausewindow.ui \
    playscene.ui \
    protutorialwidget.ui \
    resultwidget.ui \
    tutorialwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    music/mus.qrc \
    table.qrc \
    testres/testres.qrc \
    video.qrc

DISTFILES += \
    music/Sdorica ''the  Story Unfolds'' - Hoskey, RayRay.mp3 \
    music/Sound Souler - Paradise.mp3 \
    music/UM,XYLZ - ♪.mp3
