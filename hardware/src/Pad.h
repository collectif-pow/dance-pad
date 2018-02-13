#ifndef Pad_h
#define Pad_h

#include <Arduino.h>

class Pad {
	private:
		String _direction;
		int _first;
		int _second;
		int _prev;

	public:
		Pad(String direction, int first, int second);
		bool uniquePress();
		bool isPressed();
		String getDirection();
};

#endif
