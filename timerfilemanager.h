#ifndef TIMERFILEMANAGER_H
#define TIMERFILEMANAGER_H

#include <QString>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

class TimerFileManager
{
private :
    QString timerSettingFilePath;

public:
    TimerFileManager();

    void saveTimerSetting(QString soundFilePath, int soundVolume); // 타이머 세팅을 설정한다.
    void loadTimerSetting(QString& soundFilePath, int& soundVolume); // 타이머 세팅을 불러온다.
};

#endif // TIMERFILEMANAGER_H
