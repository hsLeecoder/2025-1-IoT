#include "LedToggle.h"			#클래스 만들기

LedToggle::LedToggle(int pin) {
	_pin = pin;
	_state = false;
	#_dalayTime = 0;
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
}

void LedToggle::toggle() {
	#_pin = pin;
	_state = !_state;
	#_delayTime = delayTime;
	#pinMode(_pin, OUTPUT);
	#digitalWrite(_pin, LOW);
	digitalWrite(_pin, _state ? HIGH : LOW);
}

#void LedToggle::toggle(){
#	if(_delayTime > 0) {
#		delay(_delayTime);
#	}
#	_state = !_state;
#	digitalWrite(_pin, _state ? HIGH : LOW);
#	
#}
