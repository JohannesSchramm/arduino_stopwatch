#include <Arduino.h>
#include "arduino_stopwatch.h"

using namespace ArduinoStopwatch;


Stopwatch16MS myWatch;

void setup() {
    // setup serial console:
    Serial.begin(115200);
    Serial.println("ArduinoStopwatch, stop random time example!");

}

void loop() {
    myWatch.restart();
    uint16_t waitMillis = random(200, 2000);
    delay(waitMillis);
    uint16_t watchTime = myWatch.getTimeSinceStart();
    Serial.print("Waited ");
    Serial.print(waitMillis);
    Serial.print("ms, Watch shows ");
    Serial.print(watchTime);
    Serial.println("ms!");
}