#ifndef TIMERSETTING_H
#define TIMERSETTING_H

#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QCloseEvent>

#include "timerfilemanager.h"

namespace Ui {
class TimerSetting;
}

class TimerSetting : public QDialog
{
    Q_OBJECT

public:
    explicit TimerSetting(QString& soundFilePath, int& soundVolume, QWidget *parent = nullptr);
    ~TimerSetting();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_soundFilePathButton_clicked(); // 사운드 파일 경로 설정하기
    void on_soundVolumeButton_clicked(); // 사운드 테스트하기
    void on_saveSettingButton_clicked(); // 모든 설정 저장하기
    void on_cancelButton_clicked(); // 취소하기

private:
    Ui::TimerSetting *ui;

    QString& soundFilePath; // 사운드파일 위치
    int& soundVolume; // 사운드 소리
    QMediaPlayer* player;
};

#endif // TIMERSETTING_H
