#include "timer.h"

/*
Steady loop time control

Tseren Frantsuzov
2021
*/

/*
Setup: none required
*/

/*
how many iterations have we already passed?
*/
long iterations_passed{0};

/*
how much time should the iteration span in ms?
*/
constexpr long target_duration{150};

/*
The timer with which we will ensure the timing is correct
*/
timer_ms loop_control;

/*
Stall until it`s time to begin the next iteration.
The entire mechanism can be a class although there is often little need to do so
*/
void wait_for_next_iter() {
    /*
    We want to wait until this much time passes on the timer.
    Do not increment iterations_passed yet so that possible interrupts see the right count
    */
    long target_time=target_duration*(iterations_passed+1);
    while(loop_control.get()<target_time) {
        //stall
    }
    iterations_passed++;
}

void setup() {
    Serial.begin(9600);

    //do not count the time needed to set everything up by resetting the loop control
    loop_control.reset();
}

/*
Imitate some possibly time-consuming work by stalling
*/
void generate_load() {
    if(iterations_passed%4 !=0) {
        //do not do anything on most iterations
        return;
    }
    //stall now
    delay(2*target_duration);
}

void loop() {
    //do time-consuming work
    generate_load();

    //print how many iterations have we passed
    Serial.println(iterations_passed);

    /*
    invoke the time control. When it`s too late (e. g. generate_load() consumes too much time), 
    wait_for_next_iter() will skip wait periods until we are done.
    */
    wait_for_next_iter();
}