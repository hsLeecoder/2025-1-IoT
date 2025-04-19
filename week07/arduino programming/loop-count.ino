void setup() {			#loop가 1초에 몇번 실행되는지 찍어주는 코드
  Serial.begin(115200);
  Serial.println();
}

void loop() {
  static unsigned long loopCnt = 0;
  static unsigned long nextMil = millis() + 1000;

  loopCnt++;

  if(millis() > nextMil) {
    nextMil = millis() + 1000;
    Serial.println(loopCnt);
    loopCnt = 0;
  }
}
