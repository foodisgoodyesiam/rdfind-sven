/*
   copyright 2025 Steven Marion?
   Distributed under GPL v 2.0 or later, at your option.
   See LICENSE for further details.

   this file provides functionality to print how long things took
 */
#ifndef printtime_hh
#define printtime_hh

#include <ostream>
#include <chrono>

class Timer {
  private:
    bool enabled = false;
    std::chrono::time_point<std::chrono::high_resolution_clock> prev_time;

  public:
    Timer() {};

    // enable and start the timer
    void start();
    // TODO does this actually have to be a friend? I think so...
    // if configured to do so (if start was called), prints time since either start or since previously printed
    friend std::ostream& operator<<(std::ostream& out, Timer& t);
};



#endif
