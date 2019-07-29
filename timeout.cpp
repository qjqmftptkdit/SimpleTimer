#include "timeout.h"
#include "ui_timeout.h"

TimeOut::TimeOut(QString timerName, TimerInfo timerInfo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeOut),
    timerInfo(timerInfo)
{
    ui->setupUi(this);
    ui->timerNameLabel->setText(timerName);
    this->setFixedSize(304,158);

    this->setWindowState( (windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
    this->activateWindow();
}

TimeOut::~TimeOut()
{
    delete ui;
}

void TimeOut::on_pushButton_clicked()
{
    this->close();
}
