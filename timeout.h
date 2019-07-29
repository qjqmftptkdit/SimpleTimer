#ifndef TIMEOUT_H
#define TIMEOUT_H

#include <QDialog>
#include <QString>
#include <QMediaPlayer>

#include "timerinfo.h"

namespace Ui {
class TimeOut;
}

class TimeOut : public QDialog
{
    Q_OBJECT

public:
    explicit TimeOut(QString timerName, TimerInfo timerInfo, QString soundFilePath, int soundVolume, QWidget *parent = nullptr);
    ~TimeOut();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TimeOut *ui;
    TimerInfo timerInfo;
    QMediaPlayer* player;

    QString soundFilePath; // 사운드파일 위치
    int soundVolume; // 사운드 소리
};

#endif // TIMEOUT_H
