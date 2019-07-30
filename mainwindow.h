#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "addtimer.h"
#include "timerinfo.h"
#include "timeout.h"
#include "timersetting.h"
#include "timerfilemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTimerButton_clicked(); // 타이머 추가창 실행
    void countDown(); // 1초마다 실행되어서 타이머리스트를 업데이트시킨다.

    void on_delTimerButton_clicked(); // 특정 타이머를 삭제시킨다.
    void on_delAllTimerButton_clicked(); // 모든 타이머를 삭제시킨다.

    void on_stopTimerButton_clicked(); // 특정 타이머를 일시정지시킨다.
    void on_playTimerButton_clicked(); // 특정 타이머를 재생시킨다.
    void on_initTimerButton_clicked(); // 특정 타이머를 초기화시킨다.

    void on_configTimerButton_clicked(); // 타이머관련 설정

private:
    Ui::MainWindow *ui;
    AddTimer* addTimerForm; // 타이머 추가 폼
    TimeOut* timeoutForm; // 타임아웃 폼
    TimerSetting* timerSettingForm; // 타이머 세팅 폼

    std::vector<TimerInfo> timerInfos; // 타이머 정보 저장 백터
    QTimer* countTimer; // 1초마다 실행되는 타이머

    QString soundFilePath; // 사운드파일 위치
    int soundVolume; // 사운드 소리
};

#endif // MAINWINDOW_H
