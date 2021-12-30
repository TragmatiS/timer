#include "timer.h"

/*
Timer: reset examples

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
Make a timer
*/
timer_ms time;

/*
Make a function to reset our timer whenever an 'R' arrives via the Serial port.
*/
void reset_if_needed() {
    if(!Serial.available()) {
        //nothing to read
        return;
    }

    char c=Serial.read();
    if(c!='R') {
        //not a 'R'
        return;
    }

    //By now we have a character which is a 'R'. It`s time to actually reset
    time.reset();
    Serial.print("Resetting...\n");
}

void loop() {
    //reset the tier if the user wants it
    reset_if_needed();

    Serial.println(time);

    delay(50);
}