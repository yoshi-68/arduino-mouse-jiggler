#include <Mouse.h>
#include <Adafruit_NeoPixel.h>

// Time calculation
const int SECOND = 1000;
const unsigned long TIME_TO_WAIT_FOR_MOUSE_MOVEMENT = (unsigned long)59 * SECOND;

// Mouse settings
const int MOVE_X_AXIS = 3;
const int RETURN_X_AXIS = -MOVE_X_AXIS;
const int MOVE_Y_AXIS = 0;
const int RETURN_Y_AXIS = -MOVE_Y_AXIS;

// LED settings
const int LED_PIN = 13;
const int NEOPIXEL_PIN = 4;
const int RGB_LED_NUMBER = 1;
const int RED = 255;
const int GREEN = 255;
const int BLUE = 255;
const int NO_COLOR = 0;
const int BASE_BRIGHTNESS = 10;
const Adafruit_NeoPixel neoPixel = Adafruit_NeoPixel(RGB_LED_NUMBER, NEOPIXEL_PIN, NEO_RGB + NEO_KHZ800);


void setup() {
  neoPixel.begin();
  TurnOnTheStartUpLamp();
  pinMode(LED_PIN, OUTPUT);
  delay(3 * SECOND);
  TurnOnThePowerLamp();
  delay(1 * SECOND);
  Mouse.begin();
}

void TurnOnTheStartUpLamp() {
  turnOnTheLed(BASE_BRIGHTNESS, GREEN, NO_COLOR, NO_COLOR);
}

void TurnOnThePowerLamp() {
  turnOnTheLed(BASE_BRIGHTNESS, NO_COLOR, NO_COLOR, BLUE);
}

void TurnOnTheProcLamp() {
  turnOnTheLed(BASE_BRIGHTNESS, NO_COLOR, RED, NO_COLOR);
}

void turnOnTheLed(int brightness, int red, int green, int blue) {
  neoPixel.clear();
  neoPixel.setBrightness(brightness);
  neoPixel.setPixelColor(0, red, green, blue);
  neoPixel.show();
}

void loop() {
  moveMouse();
  waitMoveMouse();
}

void moveMouse() {
  TurnOnTheProcLamp();
  Mouse.move(MOVE_X_AXIS, MOVE_Y_AXIS);
  delay(0.2 * SECOND);
  Mouse.move(RETURN_X_AXIS, RETURN_Y_AXIS);
  TurnOnThePowerLamp();
}

void waitMoveMouse() {
  delay(TIME_TO_WAIT_FOR_MOUSE_MOVEMENT);
}
