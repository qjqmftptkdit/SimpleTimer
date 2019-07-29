#include "mainwindow.h"
#include "ui_mainwindow.h"

// 타이머 메인 윈도우
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 타이머 설정
    countTimer = new QTimer(this);
    connect(countTimer, SIGNAL(timeout()), this, SLOT(countDown()));
    countTimer->start(1000); // 1초마다 실행

}

MainWindow::~MainWindow()
{
    delete ui;
}

// 타이머 추가창 실행
void MainWindow::on_addTimberButton_clicked()
{
    addTimerForm = new AddTimer(timerInfos, ui->timerList);
    addTimerForm->show();
}

// 1초마다 실행되어서 타이머리스트를 업데이트시킨다.
void MainWindow::countDown()
{
    // timerInfos에 타이머가 존재하는 경우
    if(timerInfos.size() > 0)
    {
        // 타이머 정보를 업데이트시킨다.
        for(std::vector<TimerInfo>::size_type i=0; i<timerInfos.size(); i++)
        {
            QString timerText = timerInfos[i].getTimerDown();

            if(timerText == "TimeOut") // 시간이 모두 경과된 경우
            {
                ui->timerList->item(static_cast<int>(i))->setText(timerInfos[i].getTimerOut());

                timeoutForm = new TimeOut(timerInfos[i].getTimerName(),timerInfos[i]);
                timeoutForm->show();
            }
            else if(timerText == "End") // 그후에는 무시
                continue;
            else
                ui->timerList->item(static_cast<int>(i))->setText(timerText);
        }
    }
}