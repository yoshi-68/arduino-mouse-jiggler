#include <Arduino.h>

#include "MouseJiggler.h"

const MouseJiggler JIGGLER;
static const int SECOND = 1000;
static const unsigned long TIME_TO_WAIT_FOR_MOUSE_MOVEMENT =
    (unsigned long)59 * SECOND;

static const int RGB_LED_NUMBER = 1;
static const int NEOPIXEL_PIN = 4;
static const int LED_PIN = 13;

void setup() { JIGGLER.startUp(RGB_LED_NUMBER, NEOPIXEL_PIN, LED_PIN); }

void loop() {
    JIGGLER.moveJiggle();
    delay(TIME_TO_WAIT_FOR_MOUSE_MOVEMENT);
}
