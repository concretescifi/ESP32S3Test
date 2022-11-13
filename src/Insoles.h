
#include <Arduino.h>

class Insoles { 
    public:
        Insoles();
        void printData();

        uint8_t pins[4] = {25, 26, 32, 33};
        uint8_t pinCount = 4;
}; 