
#include <Arduino.h>

class Insoles { 
    public:
        Insoles();
        void printData();

        uint8_t pins[16] = {A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17};
        uint8_t pinCount = 16;
}; 