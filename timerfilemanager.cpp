#include "timerfilemanager.h"

TimerFileManager::TimerFileManager()
{
    timerSettingFilePath = QCoreApplication::applicationDirPath() + "/timerSetting.ini";
    timerListFilePath = QCoreApplication::applicationDirPath() + "/timerList.ini";
}

// 타이머 세팅을 설정한다.
void TimerFileManager::saveTimerSetting(QString soundFilePath, int soundVolume)
{
    QFile file(timerSettingFilePath);
    if( file.open(QIODevice::WriteOnly) )
    {
        QTextStream out(&file);
        out << "soundFilePath=" << soundFilePath << "\n" ;
        out << "soundVolume=" << soundVolume ;
        file.close();
    }
}

// 타이머 세팅을 불러온다.
void TimerFileManager::loadTimerSetting(QString& soundFilePath, int& soundVolume)
{
    QFile file(timerSettingFilePath);
    if( file.open(QIODevice::ReadOnly) )
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QStringList setting = in.readLine().split("=");
            QString settingName = setting.at(0);
            QString settingVal = setting.at(1);

            if(settingName=="soundFilePath") soundFilePath = settingVal;
            if(settingName=="soundVolume") soundVolume = settingVal.toInt();
        }
       file.close();
    }
    else // 파일이 없을 경우의 디폴트 설정
    {
        soundFilePath= QCoreApplication::applicationDirPath() + "/defaultSound.wav";
        soundVolume=50;
    }
}

// 타이머 리스트를 설정한다.
void TimerFileManager::saveTimerList(std::vector<TimerInfo> timerInfos)
{
    QFile file(timerListFilePath);
    if( file.open(QIODevice::WriteOnly) )
    {
        QTextStream out(&file);
        for(std::vector<TimerInfo>::size_type i=0; i<timerInfos.size(); i++)
        {
            out << timerInfos[i].getTimerInfo() << "\n";
        }
        file.close();
    }
}

// 타이머 리스트를 불러온다.
void TimerFileManager::loadTimerList(std::vector<TimerInfo>& timerInfos, QListWidget* timerList)
{
    QFile file(timerListFilePath);
    if( file.open(QIODevice::ReadOnly) )
    {
        timerList->clear();
        timerInfos.clear();

        QTextStream in(&file);
        while(!in.atEnd())
        {
            TimerInfo timerinfo = TimerInfo(in.readLine());
            timerInfos.push_back(timerinfo);
            timerList->addItem(timerinfo.getTimerDown());
        }
       file.close();
    }
}
