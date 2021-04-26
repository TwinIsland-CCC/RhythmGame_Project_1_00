#ifndef MUSICSELECTWINDOW_H
#define MUSICSELECTWINDOW_H

#include <QWidget>
#include <QToolButton>
#include <QScrollArea>
#include <source.h>

class MusicSelectWindow : public QScrollArea
{
    Q_OBJECT
public:
    explicit MusicSelectWindow(QWidget *parent = nullptr);

signals:

private:
    QToolButton* btn[numofsong];
};

#endif // MUSICSELECTWINDOW_H
