#include "timersetting.h"
#include "ui_timersetting.h"

TimerSetting::TimerSetting(QString& soundFilePath, int& soundVolume, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerSetting),
    soundFilePath(soundFilePath),
    soundVolume(soundVolume)
{
    ui->setupUi(this);
    ui->soundFilePath->setText(soundFilePath);
    ui->soundVolume->setValue(soundVolume);
    player=nullptr;
}

TimerSetting::~TimerSetting()
{
    delete ui;
}

// 사운드 파일 경로 설정하기
void TimerSetting::on_soundFilePathButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName();
    ui->soundFilePath->setText(filePath);
}

// 사운드 테스트하기
void TimerSetting::on_soundVolumeButton_clicked()
{
    if(player)
        player->stop();

    // 소리 재생시키기
    player = new QMediaPlayer;
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile(ui->soundFilePath->text()));
    player->setVolume(ui->soundVolume->value());
    player->play();
}

// 모든 설정 저장하기
void TimerSetting::on_saveSettingButton_clicked()
{
    soundFilePath = ui->soundFilePath->text();
    soundVolume = ui->soundVolume->value();

    TimerFileManager().saveTimerSetting(soundFilePath, soundVolume);
    if(player)
        player->stop();
    this->close();
}

// 취소하기
void TimerSetting::on_cancelButton_clicked()
{
    if(player)
        player->stop();
    this->close();
}

// 윈도우 창의 취소버튼을 누를경우
void TimerSetting::closeEvent(QCloseEvent *event)
{
    if(player)
        player->stop();
    event->accept();
}
