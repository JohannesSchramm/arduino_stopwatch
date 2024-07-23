# Arduino Stopwatch Library

A PlatformIO library to stop time. Based on the Arduino framework.

## Install
### PlatformIO
Add the library to your `platformio.ini` file:
```
lib_deps = johannesschramm/ArduinoStopwatch@^1.0.2
```
or 
```
lib_deps = https://github.com/JohannesSchramm/arduino_stopwatch.git#v1.0.2
```

## Examples
Use one of the available examples to get started! 

The examples use a [RaspberryPi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/).

* [Use the Stopwatch to stop a random amount of time.](examples/stop_random_time/main.cpp)
* [Use the Stopwatch to measure the time a button is pressed.](examples/stop_button_press/main.cpp)
* [Use the Stopwatch to stop a random amount of time, which overflows the datatype.](examples/random_overflow/main.cpp)

## Documentation

Classes, functions, types, constants, ... are documented in the header files.
