#include "timer.h"

/*
Timer, basic example

Frantsuzov Tseren
2021
*/

/*
Setup: none required
*/

void setup() {
	Serial.begin(9600);
}

//Make a timer which starts at 0
timer_ms time;

void loop() {
    //Print the time
	Serial.println(time);
	
	delay(50);
}