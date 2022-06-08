#include <Arduino.h>

#include "MouseJiggler.cpp"

const MouseJiggler _JIGGLER = MouseJiggler();

void setup() { _JIGGLER.startUp(); }

void loop() {
    _JIGGLER.move();
    _JIGGLER.wait();
}
