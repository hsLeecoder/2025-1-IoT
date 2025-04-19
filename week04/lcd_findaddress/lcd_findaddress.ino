#include <LiquidCrystal_I2C.h>

#include <Wire.h>              // I2C 통신을 위한 기본 라이브러리

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Serial.println("I2C Scanner Running...");
}

void loop()
{
  Serial.println("Scanning...");

  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C 장치 발견: 0x");
      Serial.println(address, HEX);
      delay(500);
    }
  }
  Serial.println("Scan Complete! Retrying in 5 seconds...\n");
  delay(5000);
}
