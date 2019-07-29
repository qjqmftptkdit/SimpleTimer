#include "timerinfo.h"

// 타이머 정보 저장
TimerInfo::TimerInfo(int hour_s, int min_s, int sec_s, QString timerName) :
    hour_s(hour_s), min_s(min_s), sec_s(sec_s), timerName(timerName)
{
    timerStamp = sec_s + 60*min_s + 3600*hour_s ;
    isStopped = false;
}

// 타이머 카운트를 다운후에 반환시킴
QString TimerInfo::getTimerDown()
{
    // 타이머가 멈추지 않은 경우 시간 감소
    if (isStopped == false)
        timerStamp--;

    if(timerStamp == 0) return "TimeOut";
    else if(timerStamp <= 0) return "End" ;

    int hour = timerStamp/3600;
    int min = (timerStamp - 3600*hour)/60;
    int sec = timerStamp - 3600*hour - 60*min;
    return timerName + "/" + QString::number(hour_s) + ":" + QString::number(min_s) + ":" + QString::number(sec_s) + "/" + \
            QString::number(hour) + ":" + QString::number(min) + ":" + QString::number(sec);
}

// 타이머의 이름을 반환시킴
QString TimerInfo::getTimerName()
{
    return timerName;
}

// 타이머를 초기화시킨다.
void TimerInfo::timerInit()
{
    timerStamp = sec_s + 60*min_s + 3600*hour_s ;
}

// 타임아웃 정보 반환
QString TimerInfo::getTimerOut()
{
    return timerName + "/" + QString::number(hour_s) + ":" + QString::number(min_s) + ":" + QString::number(sec_s) + "/" + \
            "TimeOut";
}

// 타이머 일시정지 시키기
void TimerInfo::timerStop()
{
    if(isStopped == false) isStopped = true;
}

// 타이머 재생 시키기
void TimerInfo::timerPlay()
{
    if(isStopped == true) isStopped = false;
}
