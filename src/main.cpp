#include "Insoles.h"
#include "BNO08x.h"
#include "Haptics.h"
#include "BLE.h"


// MARK: - Properties
Insoles *insoles;
BNO08x *bno08x;
Haptics *haptics;
BLE *ble;

// MARK: - Setup
void setup() 
{
    Serial.begin(115200);

    // ble = new BLE();
    // delay(500);

    // Initialize Insoles
    insoles = new Insoles();
    delay(500);

    // Initialize BNO08x
    bno08x = new BNO08x();
    delay(500);

    // Initialize DRV2605L Hatpics driver
    haptics = new Haptics();
    delay(500);
}

void loop() 
{
    insoles->printData();
    bno08x->printIMUData();
    delay(200);

    haptics->fireEvent();
    delay(200);

    // ble->checkDeviceConnectivity();
}