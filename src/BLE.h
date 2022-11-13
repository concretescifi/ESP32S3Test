#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

#define SERVICE_UUID "033214d2-0ff0-4cba-814e-c5074c1ad00c"
#define CHARACTERISTIC_UUID "ac6744a7-77f3-43e9-b3c8-9955ac6bb0d4"

class BLE { 
    public:
        BLE();

        void checkDeviceConnectivity();
        void advertiseValues(uint8_t* values);
};