#ifndef OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class OptionWindow;
}

class OptionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OptionWindow(QWidget *parent = nullptr);
    ~OptionWindow();

signals:
    void FinishBtnpushed();
    void CancelBtnpushed();

private:
    Ui::OptionWindow *ui;
};

#endif // OPTIONWINDOW_H
