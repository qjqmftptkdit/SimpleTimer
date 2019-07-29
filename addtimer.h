#ifndef ADDTIMER_H
#define ADDTIMER_H

#include <QDialog>
#include <QListWidget>

#include "timerinfo.h"

namespace Ui {
class AddTimer;
}

class AddTimer : public QDialog
{
    Q_OBJECT

public:
    explicit AddTimer(std::vector<TimerInfo> &timerInfos, QListWidget *timerList, QWidget *parent = nullptr);
    ~AddTimer();

private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::AddTimer *ui;
    std::vector<TimerInfo> &timerInfos;
    QListWidget *timerlist;
};

#endif // ADDTIMER_H
