#pragma once

#include <chrono>
#include <fmt/format.h>

class Benchmark
{
    public:
     enum class DurationUnit
        {
            HOURS,
            MINUTES,
            SECONDS,
            MICROSECONDS,
            MILLISECONDS,
            NANOSECONDS,
        };

        void init();
        void reset();
        void stop();

        auto getTimeElapsedIn(DurationUnit unit = DurationUnit::MICROSECONDS) -> long long const;
    private:
        auto calculateTimeNow() -> std::chrono::steady_clock::time_point const;
    private:
        std::chrono::steady_clock::time_point _start, _end;
        std::chrono::steady_clock::duration _duration;
};
