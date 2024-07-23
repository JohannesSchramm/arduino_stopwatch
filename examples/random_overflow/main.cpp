#include <Arduino.h>
#include "arduino_stopwatch.h"

using namespace ArduinoStopwatch;

Stopwatch8MS myWatch;

void setup() {
    // setup serial console:
    Serial.begin(115200);
    Serial.println("ArduinoStopwatch, random overflow example!");

}

void loop() {
    uint8_t startTime = myWatch.restart();
    uint8_t waitMillis = random(50, 200);
    delay(waitMillis);
    uint8_t watchTime = myWatch.getTimeSinceStart();
    Serial.print("Start=");
    Serial.print(startTime);
    Serial.print("ms, waited=");
    Serial.print(waitMillis);
    Serial.print("ms, Watch shows ");
    Serial.print(watchTime);
    Serial.println("ms!");
}