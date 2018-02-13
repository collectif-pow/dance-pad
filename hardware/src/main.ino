#include <Pad.h>

Pad top("top", A0, A1);
Pad left("left", A2, A3);
Pad right("right", A4, A5);
Pad bottom("bottom", A6, A7);

String previous = "";
String state = "";

void setup() {
	Serial.begin(9600);
}

void loop() {
	handlePads();
	delay(100);
}

void handlePads() {
	bool topPressed = top.isPressed();
	bool leftPressed = left.isPressed();
	bool rightPressed = right.isPressed();
	bool bottomPressed = bottom.isPressed();
	state = "";
	if (topPressed && leftPressed) state = "#top#left";
	else if (topPressed && rightPressed) state = "#top#right";
	else if (topPressed && bottomPressed) state = "#top#bottom";
	else if (leftPressed && rightPressed) state = "#left#right";
	else if (topPressed) state = "#top";
	else if (leftPressed) state = "#left";
	else if (rightPressed) state = "#right";
	else if (bottomPressed) state = "#bottom";
	if (state != "" && state != previous) Serial.println(state);
	previous = state;
}


// void handlePad(Pad &pad, int factor) {
// 	if (pad.isPressed()) state += factor;
// }
// void handlePads() {
// 	state = 0;
// 	handlePad(top, 1);
// 	handlePad(left, 10);
// 	handlePad(right, 100);
// 	handlePad(bottom, 1000);
// 	if (state != previousState) {
// 		switch (state) {
// 			case 1:
// 				Serial.println("#top");
// 				previousState = state;
// 				break;
// 			case 10:
// 				Serial.println("#left");
// 				previousState = state;
// 				break;
// 			case 100:
// 				Serial.println("#right");
// 				previousState = state;
// 				break;
// 			case 1000:
// 				Serial.println("#bottom");
// 				previousState = state;
// 				break;
// 			case 11:
// 				Serial.println("#top#left");
// 				previousState = state;
// 				break;
// 			case 101:
// 				Serial.println("#top#right");
// 				previousState = state;
// 				break;
// 			case 110:
// 				Serial.println("#left#right");
// 				previousState = state;
// 				break;
// 			case 1001:
// 				Serial.println("#top#bottom");
// 				previousState = state;
// 				break;
// 			default:
// 				previousState = state;
// 				break;
// 		}
// 	}
// }
