// C++ code
//
#define TRIG 12
#define ECHO 11

int led_r = 7;
int led_g = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  long duration, distance;
 
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
 
  duration = pulseIn(ECHO, HIGH);
 
  distance = duration * 17 / 1000;
  Serial.println(duration);
  Serial.print("\nDistance : ");
  Serial.print(distance);
  Serial.println(" Cm");
 
  digitalWrite(led_r, HIGH);
  digitalWrite(led_g, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(led_r, LOW);
  digitalWrite(led_g, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
}