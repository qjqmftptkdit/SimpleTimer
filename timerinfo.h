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

    bool isStopped; // 타이머의 멈춤 여부를 나타낸다.

public :
    explicit TimerInfo(int hour_s, int min_s, int sec_s, QString timerName);

    QString getTimerDown(); // 타이머 카운트를 다운후에 반환시킴
    QString getTimerName(); // 타이머의 이름을 반환시킴
    QString getTimerOut(); // 타임아웃 정보 반환

    void timerInit(); // 타이머를 초기화시킨다.
    void timerStop(); // 타이머 일시정지 시키기
    void timerPlay(); // 타이머 재생 시키기
};

#endif // TIMERINFO_H
