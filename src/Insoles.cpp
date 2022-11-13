#include "Insoles.h"

Insoles::Insoles()
{
    Serial.printf("Initializing Insoles...");
}

void Insoles::printData()
{
    for(uint8_t i = 0; i < this->pinCount; i++) 
    {
        uint16_t value = analogRead(this->pins[i]);
        Serial.printf("%d: %d\n", this->pins[i], value);
    }
    Serial.printf("\n");
}