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
    player = new QMediaPlayer;
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile(soundFilePath));
    player->setVolume(soundVolume);
    player->play();
}

TimeOut::~TimeOut()
{
    delete ui;
}

void TimeOut::on_pushButton_clicked()
{
    this->close();
}
