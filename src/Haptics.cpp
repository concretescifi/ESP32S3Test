#include "Haptics.h"

Haptics::Haptics()
{
    Serial.printf("Initializing Haptics...");
    drv.begin();
    
    // I2C trigger by sending 'go' command 
    drv.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command

    drv.selectLibrary(1);
    drv.setWaveform(0, 84);  // ramp up medium 1, see datasheet part 11.2
    drv.setWaveform(1, 1);  // strong click 100%, see datasheet part 11.2
    drv.setWaveform(2, 0);  // end of waveforms
}

void Haptics::fireEvent()
{
    drv.go();
}