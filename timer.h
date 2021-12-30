#pragma once

typedef unsigned long (*time_source_function)();

template<time_source_function time_source>
class timer {
  public:
    //construct from begin time
    timer(long begin_time=0);
  
    //get time
    long get() const;

    //get time w/o calling get()
    operator long() const;
	
    void reset();
    
  private:
    long diff_to_present;
};

typedef timer<millis> timer_ms;
typedef timer<micros> timer_mcs;

template<time_source_function time_source>
timer<time_source>::timer(long begin_time) :
  diff_to_present(time_source()-begin_time)
{}

template<time_source_function time_source>
long timer<time_source>::get() const {
  return time_source()-diff_to_present;
}

template<time_source_function time_source>
timer<time_source>::operator long() const {
  return this->get();
}

template<time_source_function time_source>
void timer<time_source>::reset() {
  diff_to_present=time_source();
}