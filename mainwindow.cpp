#include "mainwindow.h"
#include "ui_mainwindow.h"

// 타이머 메인 윈도우
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(252,350);

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
void MainWindow::on_addTimerButton_clicked()
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

// 특정 타이머를 삭제시킨다.
void MainWindow::on_delTimerButton_clicked()
{
    if(ui->timerList->selectedItems().size() != 0)
    {
        timerInfos.erase(timerInfos.begin() + ui->timerList->currentRow());
        qDeleteAll(ui->timerList->selectedItems());
    }
}

// 모든 타이머를 삭제시킨다.
void MainWindow::on_delAllTimerButton_clicked()
{
    timerInfos.clear();
    ui->timerList->clear();
}

// 특정 타이머를 일시정지시킨다.
void MainWindow::on_stopTimerButton_clicked()
{
    if(ui->timerList->selectedItems().size() != 0)
    {
        timerInfos.at(static_cast<std::vector<int>::size_type>(ui->timerList->currentRow())).timerStop();
    }
}

// 특정 타이머를 재생시킨다.
void MainWindow::on_playTimerButton_clicked()
{
    if(ui->timerList->selectedItems().size() != 0)
    {
        timerInfos.at(static_cast<std::vector<int>::size_type>(ui->timerList->currentRow())).timerPlay();
    }
}

// 특정 타이머를 초기화시킨다.
void MainWindow::on_initTimerButton_clicked()
{
    if(ui->timerList->selectedItems().size() != 0)
    {
        timerInfos.at(static_cast<std::vector<int>::size_type>(ui->timerList->currentRow())).timerInit();
    }
}

// 타이머관련 설정을 한다.
void MainWindow::on_pushButton_2_clicked()
{
    timerSettingForm = new TimerSetting();
    timerSettingForm->show();
}
