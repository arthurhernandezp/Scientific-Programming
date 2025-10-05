#include "Benchmark.hpp"

void Benchmark::init()
{
    _start = calculateTimeNow();
}

void Benchmark::reset()
{
    _start    = std::chrono::steady_clock::time_point{};
    _end      = std::chrono::steady_clock::time_point{};
    _duration = std::chrono::steady_clock::duration::zero();
}

void Benchmark::stop()
{
    _end = calculateTimeNow();
    _duration = _end - _start;
}

auto Benchmark::getTimeElapsedIn(DurationUnit unit) -> long long const
{
    switch (unit)
    {
        case DurationUnit::HOURS        : return std::chrono::duration_cast<std::chrono::hours>(_duration).count();
        case DurationUnit::MINUTES      : return std::chrono::duration_cast<std::chrono::minutes>(_duration).count();
        case DurationUnit::SECONDS      : return std::chrono::duration_cast<std::chrono::seconds>(_duration).count();
        case DurationUnit::MILLISECONDS : return std::chrono::duration_cast<std::chrono::milliseconds>(_duration).count();
        case DurationUnit::MICROSECONDS : return std::chrono::duration_cast<std::chrono::microseconds>(_duration).count();
        case DurationUnit::NANOSECONDS  : return std::chrono::duration_cast<std::chrono::nanoseconds>(_duration).count();
    }
    return 0;
}

auto Benchmark::calculateTimeNow() -> std::chrono::steady_clock::time_point const
{
    return std::chrono::steady_clock::now();
}
