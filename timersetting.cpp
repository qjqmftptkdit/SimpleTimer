#include "timersetting.h"
#include "ui_timersetting.h"

TimerSetting::TimerSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerSetting)
{
    ui->setupUi(this);
}

TimerSetting::~TimerSetting()
{
    delete ui;
}

void TimerSetting::on_pushButton_4_clicked()
{
    this->close();
}
