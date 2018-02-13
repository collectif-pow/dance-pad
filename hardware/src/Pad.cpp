#include <Pad.h>

const int treshold = 50;

Pad::Pad(String direction, int first, int second) :
	_direction(direction), _first(first), _second(second), _prev(false) {

	pinMode(_first, INPUT);
	pinMode(_second, INPUT);
}

bool Pad::uniquePress() {
	int current = max(analogRead(_first), analogRead(_second));
	bool isUniquePress = false;
	if (current > treshold && _prev < treshold) {
		isUniquePress = true;
	}
	_prev = current;
	return isUniquePress;
}

bool Pad::isPressed() {
	return max(analogRead(_first), analogRead(_second)) > treshold;
}

String Pad::getDirection() {
	return _direction;
}
