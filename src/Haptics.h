#include <Wire.h>
#include "Adafruit_DRV2605.h"

class Haptics {     
    public:
        Haptics();
        void fireEvent();

        Adafruit_DRV2605 drv;

        uint8_t _sda = A1;
        uint8_t _scl = A0;
};