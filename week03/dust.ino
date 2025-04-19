int Vo = A0;
int V_LED = 2;

float Vo_value=0;
float Voltage=0;
float dustDensity=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(V_LED, OUTPUT);
  pinMode(Vo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(V_LED,LOW);
  delayMicroseconds(280);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_LED,HIGH);
  delayMicroseconds(9680);

  Voltage = Vo_value*5.0 / 1023.0;
  dustDensity = (Voltage - 0.3)/0.005;
  
  Serial.print("dust=");
  Serial.println(Vo_value);

  delay(1000);
}