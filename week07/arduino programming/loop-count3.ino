#include <LedToggle.h>			#만든 클래스 이용해서 led 0.5초마다 깜빡이기

LedToggle led(LED_BUILTIN);

void setup() {
}

void loop() {
  led.toggle();
  delay(500);

}