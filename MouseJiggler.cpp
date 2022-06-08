#include <Mouse.h>

#include "StatusLed.cpp"
#include "const.h"

class MouseJiggler {
   private:
    const StatusLed _LED;

    // Time calculation
    static const unsigned long _TIME_TO_WAIT_FOR_MOUSE_MOVEMENT =
        (unsigned long)59 * _SECOND;

    // Mouse settings
    static const int _MOVE_X_AXIS = 3;
    static const int _RETURN_X_AXIS = -_MOVE_X_AXIS;
    static const int _MOVE_Y_AXIS = 0;
    static const int _RETURN_Y_AXIS = -_MOVE_Y_AXIS;

    const int _LED_PIN = 13;

   public:
    MouseJiggler() : _LED(StatusLed()) {}

    void startUp() {
        _LED.begin();
        _LED.turnOnTheStartUp();
        pinMode(_LED_PIN, OUTPUT);
        delay(1 * _SECOND);
        _LED.turnOnThePower();
        delay(1 * _SECOND);
        Mouse.begin();
    }

    void move() {
        _LED.turnOnTheProc();
        Mouse.move(_MOVE_X_AXIS, _MOVE_Y_AXIS);
        delay(0.2 * _SECOND);
        Mouse.move(_RETURN_X_AXIS, _RETURN_Y_AXIS);
        _LED.turnOnThePower();
    }

    void wait() { delay(_TIME_TO_WAIT_FOR_MOUSE_MOVEMENT); }
};
