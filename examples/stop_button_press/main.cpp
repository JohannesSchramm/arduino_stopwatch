#include <Arduino.h>
#include "arduino_stopwatch.h"

using namespace ArduinoStopwatch;

const int BUTTON_PIN = 7;
Stopwatch16MS myWatch;

void setup() {
    // setup serial console:
    Serial.begin(115200);
    Serial.println("ArduinoStopwatch, stop button press example!");

    // setup pin:
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
    if(digitalRead(BUTTON_PIN) == LOW) {
        myWatch.restart();
        while(myWatch.getTimeSinceStart() < 60000) {
            if(digitalRead(BUTTON_PIN) == HIGH) {
                break;
            }
        }
        uint16_t watchTime = myWatch.getTimeSinceStart();
        Serial.print("The button was ");
        Serial.print(watchTime);
        Serial.println("ms pressed!");
    }
}