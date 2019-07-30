Simple Timer
==

1.개요
--
GitFlow, TTD, QT 등을 연습할 겸 만들게 된 타이머 프로젝트.

2.각각의 파일 설명
--
* mainwindow.cpp  
타이머의 가장 중심이 되는 클래스.  
타이머 추가/삭제/일시정지/재생/초기화/저장/불러오기등을 위한 클래스를 생성할 수 있다.

* addtimer.cpp
타이머 추가를 위해서 사용되는 클래스.  
타이머의 이름을 입력하거나 타이머 시간을 설정할 수 있다.  

* timeout.cpp  
이용자에게 시간이 모두 경과되었음을 알려주기 위한 UI 및 기능이 들어있는 클래스.

* timerinfo.cpp  
타이머에 관한 정보를 저장하고, 타이머의 정보를 등록하거나 얻을 수 있게 만들어둔 클래스.

* timerfilemanager.cpp  
타이머 관련 정보를 파일에 저장하고 불러오는 것을 구현하기 위한 클래스.

* timersetting.cpp  
타이머에 사용되는 소리와 소리크기를 조절하고, 이를 파일에 저장하기 위한 클래스.