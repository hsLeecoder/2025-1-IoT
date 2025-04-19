#ifndef LedToggle_h
#define LedToggle_h

#include "Arduino.h"

class LedToggle {
public:
	LedToggle(int pin);
	#LedToggle(int pin, unsigned long delayTime);
	void toggle();
private:
	int _pin;			#private에서 선언한 변수는 언더바로 구분
	bool _state;
	#unsigner long _delayTime;
};
#endif

