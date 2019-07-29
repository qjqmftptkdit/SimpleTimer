#include "addtimer.h"
#include "ui_addtimer.h"

// 타이머 추가 창
AddTimer::AddTimer(std::vector<TimerInfo> &timerInfos, QListWidget *timerList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTimer),
    timerInfos(timerInfos),
    timerlist(timerList)
{
    ui->setupUi(this);
}

AddTimer::~AddTimer()
{
    delete ui;
}

void AddTimer::on_cancelButton_clicked()
{
    this->close();
}

// 타이머 추가 버튼 클릭
void AddTimer::on_okButton_clicked()
{
    TimerInfo timerinfo(static_cast<int>(this->ui->hourBox->value()), static_cast<int>(this->ui->minBox->value()), static_cast<int>(this->ui->secBox->value()), this->ui->timerName->text());
    timerInfos.push_back(timerinfo); // 생성된 타이머 정보를 백터 끝에 추가시킨다.
    timerlist->addItem(timerinfo.getTimerDown()); // 생성된 타이머 정보를 리스트에 추가시킨다.
    this->close();
}
