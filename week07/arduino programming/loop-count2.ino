#include <SimpleTimer.h>			#라이브러리를 이용한 1초 이상의 간격으로 주기적으로 센서 데이터를 취득하는 것

SimpleTimer timerCnt;

unsigned long loopCnt;

void timerCntFunc() {
  Serial.println(loopCnt);
  loopCnt = 0;
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  timerCnt.setInterval(1000,timerCntFunc);
}

void loop() {
  timerCnt.run();
  loopCnt++; 
}
