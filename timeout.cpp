#include "timeout.h"
#include "ui_timeout.h"

TimeOut::TimeOut(QString timerName, TimerInfo timerInfo, QString soundFilePath, int soundVolume, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeOut),
    timerInfo(timerInfo),
    soundFilePath(soundFilePath),
    soundVolume(soundVolume)
{
    ui->setupUi(this);
    ui->timerNameLabel->setText(timerName);
    this->setFixedSize(304,158);

    this->setWindowState( (windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
    this->activateWindow();

    // 소리 재생시키기
    player = new QMediaPlayer();
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile(soundFilePath));
    player->setVolume(soundVolume);
    player->play();
}

TimeOut::~TimeOut()
{
    qDebug() << "HELLO";
    delete ui;
}

void TimeOut::on_pushButton_clicked()
{
    player->stop();
    this->close();
}

// 윈도우 창의 취소버튼을 누를경우
void TimeOut::closeEvent(QCloseEvent *event)
{
    player->stop();
    event->accept();
}
