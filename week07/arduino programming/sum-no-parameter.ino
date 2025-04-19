int a1 = 2;			#함수를 호출하고 만드는 방법(매개 변수 참조 값이 바뀌는 변수는 매개 변수 앞에 &를 붙임)
int a2 = 3;
int a3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  sum(a1, a2, a3);
  Serial.println(a3);
}

void loop() {

}

void sum(int a, int b, int& c) {
  c = a + b;
}
