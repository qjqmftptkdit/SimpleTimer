#ifndef TIMERFILEMANAGER_H
#define TIMERFILEMANAGER_H

#include <QString>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QListWidget>

#include <timerinfo.h>

class TimerFileManager
{
private :
    QString timerSettingFilePath;
    QString timerListFilePath;

public:
    TimerFileManager();

    void saveTimerSetting(QString soundFilePath, int soundVolume); // 타이머 세팅을 설정한다.
    void loadTimerSetting(QString& soundFilePath, int& soundVolume); // 타이머 세팅을 불러온다.

    void saveTimerList(std::vector<TimerInfo> timerInfos); // 타이머 리스트를 설정한다.
    void loadTimerList(std::vector<TimerInfo>& timerInfos, QListWidget* timerList); // 타이머 리스트를 불러온다.
};

#endif // TIMERFILEMANAGER_H
