#pragma once

class MouseJiggler {
   private:
    static const int MOVE_X_AXIS = 3;
    static const int RETURN_X_AXIS = -MOVE_X_AXIS;
    static const int MOVE_Y_AXIS = 0;
    static const int RETURN_Y_AXIS = -MOVE_Y_AXIS;
    static const int NO_COLOR = 0;
    static const int BASE_BRIGHTNESS = 10;

    void turnOnTheLed(int brightness, int red, int green, int blue);
    void turnOnTheStartUp();
    void turnOnThePower();
    void turnOnTheProc();

   public:
    MouseJiggler();
    void startUp(int rgbLedNumber, int neoPixelPin, int ledPin);
    void moveJiggle();
};
