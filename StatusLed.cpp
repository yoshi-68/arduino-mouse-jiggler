#include <Adafruit_NeoPixel.h>

class StatusLed {
   private:
    const Adafruit_NeoPixel _NEO_PIXEL;
    static const int _NO_COLOR = 0;
    static const int _BASE_BRIGHTNESS = 10;
    static const int _RGB_LED_NUMBER = 1;
    static const int _NEOPIXEL_PIN = 4;

   public:
    StatusLed()
        : _NEO_PIXEL(Adafruit_NeoPixel(_RGB_LED_NUMBER, _NEOPIXEL_PIN,
                                       NEO_RGB + NEO_KHZ800)) {}

    void begin() { _NEO_PIXEL.begin(); }

    void turnOnTheLed(int brightness, int red, int green, int blue) {
        _NEO_PIXEL.clear();
        _NEO_PIXEL.setBrightness(brightness);
        _NEO_PIXEL.setPixelColor(0, red, green, blue);
        _NEO_PIXEL.show();
    }

    void turnOnTheStartUp() {
        turnOnTheLed(_BASE_BRIGHTNESS, 255, _NO_COLOR, _NO_COLOR);
    }

    void turnOnThePower() {
        turnOnTheLed(_BASE_BRIGHTNESS, _NO_COLOR, _NO_COLOR, 255);
    }

    void turnOnTheProc() {
        turnOnTheLed(_BASE_BRIGHTNESS, _NO_COLOR, 255, _NO_COLOR);
    }
};
