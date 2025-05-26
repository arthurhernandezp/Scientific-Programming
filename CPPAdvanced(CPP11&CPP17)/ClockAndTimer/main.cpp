#include <iostream>
#include <chrono>

/*
 * Introduce to <chrono>
 *  -- A precision-neutral library for time and date
 *
 *  Chrono Concepts:
 *
 *  Clock: Chrono provides 3 types of clock
 *      1. std::chrono::system_clock: current time according to the system (toolbar hour) - is not steady
 *      2. std::chrono::steady_clock: goes at a uniform rate
 *      3. std::chrono::high_resolution_clock: provides smallest possible tick period.
 *
 *  Duration:
 *      std::chrono::duration<>:    represents time duration
 *      How to represent 2 hours? You need a number and a unit.
 *      Example:
 *          1. duration<int,ratio<1,1>>        //number of seconds stored in a int (ration<1,1> represent 1 second
 *          2. duration<double,ratio<60,1>>    //number of minutes stored in a double
 *
 *      Pre defined duration by chrono:
 *          1. nanoseconds
 *          2. microseconds
 *          3. milliseconds
 *          4. seconds
 *          5. minutes
 *          6. hours
 *
 *  Point of Time(time_point):
 *      - std::chrono::time_point<>: represents a point of time
 *      00:00 January 1,1970 (Corordinated Universal Time - UTC) -- epoch of a clock
 *      Define a time of point
 *          time_point<system_clock,milliseconds>: according to system_clock, the elapsed time since epoch in milliseconds.
 *
 */

int main()
{
    // In C++ Clock frequenc, what period is represented with a ratio
    std::ratio<1,10> r;     //   r  =   1/10
    std::ratio<2,10> r2;    //  r2 =   1/5
    std::cout << r.num << '/' << r.den << std::endl;

    std::cout << std::chrono::system_clock::period::num << '/' << std::chrono::system_clock::period::den << std::endl;

    // How to use point of time
        std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();   //  current time of system_clock
        std::cout << timeNow.time_since_epoch().count() << std::endl;   // Number of cycles since time of apoch
        timeNow = timeNow + std::chrono::seconds(2);
        std::cout << timeNow.time_since_epoch().count() << std::endl;   // Number of cycles since time of apoch

        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        std::cout << "any message" << std::endl;
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::chrono::steady_clock::duration d = end - start;
        if (d == std::chrono::steady_clock::duration::zero())
            std::cout << "no time elapsed" << std::endl;

        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(d).count() << std::endl;
    return 0;
}