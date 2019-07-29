#ifndef TIMERINFO_H
#define TIMERINFO_H

#include <QString>
#include <vector>

class TimerInfo
{
private :
    int hour_s;
    int min_s;
    int sec_s;
    QString timerName;

    int timerStamp;

public :
    explicit TimerInfo(int hour_s, int min_s, int sec_s, QString timerName);
    QString getTimerDown();
    QString getTimerName();
    QString getTimerOut();
    void timerInit();

};

#endif // TIMERINFO_H
