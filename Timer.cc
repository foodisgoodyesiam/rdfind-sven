/*
   copyright 2025 Steven Marion?
   Distributed under GPL v 2.0 or later, at your option.
   See LICENSE for further details.

   this file provides functionality to print how long things took
 */

#include "Timer.hh"

void
Timer::start()
{
  enabled = true;
  prev_time = std::chrono::high_resolution_clock::now();
}

std::ostream&
operator<<(std::ostream& out, Timer& t)
{
  if (t.enabled) {
    const std::chrono::time_point<std::chrono::high_resolution_clock> new_time =
      std::chrono::high_resolution_clock::now();
    // TODO
    std::chrono::nanoseconds::rep ns_dur =
      std::chrono::duration_cast<std::chrono::nanoseconds>(new_time -
                                                           t.prev_time)
        .count();
    out << " (" << (static_cast<double>(ns_dur) / 1000000000.0) << " seconds)";
    t.prev_time = new_time;
  }
  return out;
}
