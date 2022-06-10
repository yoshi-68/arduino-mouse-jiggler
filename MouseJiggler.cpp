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
    MouseJiggler::turnOnTheLed(MouseJiggler::BASE_BRIGHTNESS, 255,
                               MouseJiggler::NO_COLOR, MouseJiggler::NO_COLOR);
}

void MouseJiggler::turnOnThePower() {
    MouseJiggler::turnOnTheLed(MouseJiggler::BASE_BRIGHTNESS,
                               MouseJiggler::NO_COLOR, MouseJiggler::NO_COLOR,
                               255);
}

void MouseJiggler::turnOnTheProc() {
    MouseJiggler::turnOnTheLed(MouseJiggler::BASE_BRIGHTNESS,
                               MouseJiggler::NO_COLOR, 255,
                               MouseJiggler::NO_COLOR);
}

MouseJiggler::MouseJiggler() {}

void MouseJiggler::startUp(int rgbLedNumber, int neoPixelPin, int ledPin) {
    NEO_PIXEL =
        Adafruit_NeoPixel(rgbLedNumber, neoPixelPin, NEO_RGB + NEO_KHZ800);
    NEO_PIXEL.begin();
    MouseJiggler::turnOnTheStartUp();
    pinMode(ledPin, OUTPUT);
    delay(1000);
    MouseJiggler::turnOnThePower();
    delay(1000);
    Mouse.begin();
}

void MouseJiggler::moveJiggle() {
    MouseJiggler::turnOnTheProc();
    Mouse.move(MouseJiggler::MOVE_X_AXIS, MouseJiggler::MOVE_Y_AXIS);
    delay(200);
    Mouse.move(MouseJiggler::RETURN_X_AXIS, MouseJiggler::RETURN_Y_AXIS);
    MouseJiggler::turnOnThePower();
}
