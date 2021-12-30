#include "timer.h"

/*
Timer w/a custom time source function

Frantsuzov Tseren
2021
*/

/*
Setup: none required
*/

void setup() {
	Serial.begin(9600);
}

/*
Make a function which returns our time.
In this case it is just millis/2.
*/
unsigned long custom_time_source() {
	return millis()/2;
}

/*
Make a timer using the time source we just made.
*/
timer<custom_time_source> time;

void loop() {
	Serial.println(time);

	delay(50);
}