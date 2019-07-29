#ifndef TIMEOUT_H
#define TIMEOUT_H

#include <QDialog>
#include <QString>

#include "timerinfo.h"

namespace Ui {
class TimeOut;
}

class TimeOut : public QDialog
{
    Q_OBJECT

public:
    explicit TimeOut(QString timerName, TimerInfo timerInfo, QWidget *parent = nullptr);
    ~TimeOut();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TimeOut *ui;
    TimerInfo timerInfo;
};

#endif // TIMEOUT_H
