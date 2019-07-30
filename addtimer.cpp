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
    this->setFixedSize(298,149);
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
    // 아무것도 설정하지 않은 경우 종료
    if(this->ui->secBox->value()==0.0 && this->ui->minBox->value()==0.0 && this->ui->hourBox->value()==0.0)
    {
        this->close();
        return;
    }

    // 타이머 이름이 비었으면 임의의 이름으로 설정
    QString timerName = this->ui->timerName->text();
    if(timerName.size() == 0) timerName = QString("Timer").append(QString::number(timerlist->count()));

    TimerInfo timerinfo(static_cast<int>(this->ui->hourBox->value()), static_cast<int>(this->ui->minBox->value()), static_cast<int>(this->ui->secBox->value()), timerName);
    timerInfos.push_back(timerinfo); // 생성된 타이머 정보를 백터 끝에 추가시킨다.
    timerlist->addItem(timerinfo.getTimerDown()); // 생성된 타이머 정보를 리스트에 추가시킨다.
    this->close();
}
