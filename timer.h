#include <time.h>
#define POSIX 1
#define WINDOWS 2
//Generally you want to use the POSIX version.  Its better, more accurate.  But, the
//function won't work on non-posix systems... so switch to WINDOWS if you are using VS
#define PLATFORM POSIX

/*This class represents a timer.  A timer can be used to get the wall clock
time it took for a piece of code to be run.

When initialized, the timer is set to 0.  In order to start timing, the 
start() function must be used.  

The following are the member functions of Timer and their usage:

  start();  starts the clock running from the current time
  currtime();  returns the current time
  stop();  stops the clock without reseting its value
  reset();  stops the clock and resets the timer to 0
*/

class Timer{
#if PLATFORM == WINDOWS
    clock_t starttime_;
    clock_t stoptime_;
#else
    struct timespec starttime_;
    struct timespec stoptime_;
#endif
    double elapsedTime_;
    bool isstop_;
public:
    Timer();
    void reset();
    void start();
    void stop();
    double currtime();
    double starttime();
};
