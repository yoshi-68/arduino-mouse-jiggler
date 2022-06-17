#include "MouseJiggler.h"

#include <Adafruit_NeoPixel.h>
#include <Mouse.h>

const Adafruit_NeoPixel NEO_PIXEL;

void MouseJiggler::turnOnTheLed(int brightness, int red, int green, int blue) {
    NEO_PIXEL.clear();
    NEO_PIXEL.setBrightness(brightness);
    NEO_PIXEL.setPixelColor(0, red, green, blue);
    NEO_PIXEL.show();
}

void MouseJiggler::turnOnTheStartUp() {
    turnOnTheLed(BASE_BRIGHTNESS, 255, NO_COLOR, NO_COLOR);
}

void MouseJiggler::turnOnThePower() {
    turnOnTheLed(BASE_BRIGHTNESS, NO_COLOR, NO_COLOR, 255);
}

void MouseJiggler::turnOnTheProc() {
    turnOnTheLed(BASE_BRIGHTNESS, NO_COLOR, 255, NO_COLOR);
}

MouseJiggler::MouseJiggler() {}

void MouseJiggler::bigin(int rgbLedNumber, int neoPixelPin, int ledPin) {
    NEO_PIXEL =
        Adafruit_NeoPixel(rgbLedNumber, neoPixelPin, NEO_RGB + NEO_KHZ800);
    NEO_PIXEL.begin();
    turnOnTheStartUp();
    pinMode(ledPin, OUTPUT);
    delay(1000);
    turnOnThePower();
    delay(1000);
    Mouse.begin();
}

void MouseJiggler::moveJiggle() {
    turnOnTheProc();
    Mouse.move(MOVE_X_AXIS, MOVE_Y_AXIS);
    delay(200);
    Mouse.move(RETURN_X_AXIS, RETURN_Y_AXIS);
    turnOnThePower();
}
