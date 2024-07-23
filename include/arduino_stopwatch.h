#pragma once
#include <Arduino.h>

namespace ArduinoStopwatch {

/// @brief Type for the unit of time.
enum class TimeUnit {
    MS, /// Milliseconds
    US  /// Microseconds
};

/// @brief Template for a Stopwatch class.
/// @tparam TValue Type of the variables used to store time values.
/// @tparam typeMaxValue Maximum value that the type 'TValue' supports before overflowing
/// @tparam unit Unit of time used by the Stopwatch.
template <typename TValue, TValue typeMaxValue, TimeUnit unit>
class Stopwatch {
public:
    /// @brief Constructs a new Stopwatch object.
    Stopwatch() : startTime(0) {}
    /// @brief Resets the start time to the current system time.
    /// @return Start time.
    TValue restart() {
        startTime = getTime();
        return startTime;
    }
    /// @brief Gets the time since the last time `restart()` was called.
    /// @return Time since the last restart.
    TValue getTimeSinceStart() const {
        TValue currentTime = getTime();
        if(currentTime >= startTime) {
            return (currentTime - startTime);
        } else {
            return (typeMaxValue - startTime + currentTime + 1);
        }
    }
    /// @brief Gets the used unit of time.
    /// @return Unit of time.
    TimeUnit getUnit() const {
        return unit;
    }    
    /// @brief Gets the current system time.
    /// @return Current time.
    TValue getTime() const {
        switch (unit)
        {
        case TimeUnit::MS: return (TValue)millis();
        case TimeUnit::US: return (TValue)micros();
        default: return 0;
        }
    }
    /// @brief Gets the time the stopwatch was restarted.
    /// @return Start time.
    TValue getStartTime() const {
        return startTime;
    }
private:
    TValue startTime;
};

/// @brief Stopwatch in milliseconds based on `uint8_t`.
/// @details Stopwatch class that uses `uint8_t` as the base type and miliseconds as the unit of time.
using Stopwatch8MS = Stopwatch<uint8_t, UINT8_MAX, TimeUnit::MS>;
/// @brief Stopwatch in milliseconds based on `uint16_t`.
/// @details Stopwatch class that uses `uint16_t` as the base type and miliseconds as the unit of time.
using Stopwatch16MS = Stopwatch<uint16_t, UINT16_MAX, TimeUnit::MS>;
/// @brief Stopwatch in milliseconds based on `uint32_t`.
/// @details Stopwatch class that uses `uint32_t` as the base type and miliseconds as the unit of time.
using Stopwatch32MS = Stopwatch<uint32_t, UINT32_MAX, TimeUnit::MS>;
/// @brief Stopwatch in microseconds based on `uint8_t`.
/// @details Stopwatch class that uses `uint8_t` as the base type and microseconds as the unit of time.
using Stopwatch8US = Stopwatch<uint8_t, UINT8_MAX, TimeUnit::US>;
/// @brief Stopwatch in microseconds based on `uint16_t`.
/// @details Stopwatch class that uses `uint16_t` as the base type and microseconds as the unit of time.
using Stopwatch16US = Stopwatch<uint16_t, UINT16_MAX, TimeUnit::US>;
/// @brief Stopwatch in microseconds based on `uint32_t`.
/// @details Stopwatch class that uses `uint32_t` as the base type and microseconds as the unit of time.
using Stopwatch32US = Stopwatch<uint32_t, UINT32_MAX, TimeUnit::US>;

}