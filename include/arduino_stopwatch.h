#pragma once
#include <Arduino.h>

namespace ArduinoStopwatch {

enum class TimeUnit {MS, US};

template <typename TValue, TValue typeMaxValue, TimeUnit unit>
class Stopwatch {
public:
    Stopwatch() : startTime(0) {}
    void restart() {
        startTime = getTime();
    }
    TValue getTimeSinceStart() const {
        TValue currentTime = getTime();
        if(currentTime >= startTime) {
            return (currentTime - startTime);
        } else {
            return (typeMaxValue - startTime + currentTime);
        }
    }
    TimeUnit getUnit() const {
        return unit;
    }
    TValue getTime() const {
        switch (unit)
        {
        case TimeUnit::MS: return (TValue)millis();
        case TimeUnit::US: return (TValue)micros();
        default: return 0;
        }
    }
private:
    TValue startTime;
};

using Stopwatch8MS = Stopwatch<uint8_t, UINT8_MAX, TimeUnit::MS>;
using Stopwatch16MS = Stopwatch<uint16_t, UINT16_MAX, TimeUnit::MS>;
using Stopwatch32MS = Stopwatch<uint32_t, UINT32_MAX, TimeUnit::MS>;
using Stopwatch8US = Stopwatch<uint8_t, UINT8_MAX, TimeUnit::US>;
using Stopwatch16US = Stopwatch<uint16_t, UINT16_MAX, TimeUnit::US>;
using Stopwatch32US = Stopwatch<uint32_t, UINT32_MAX, TimeUnit::US>;

}