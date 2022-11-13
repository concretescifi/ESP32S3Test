#include <Wire.h>
#include "SparkFun_BNO080_Arduino_Library.h"

class BNO08x
{
    public:
        BNO08x();
        void printIMUData();
        
        uint8_t _scl = A0;
        uint8_t _sda = A1;

        BNO080 myIMU;
};