#include "BNO08x.h"

BNO08x::BNO08x() 
{ 

    Wire.begin(_sda, _scl);

    //   Are you using a ESP? Check this issue for more information: https://github.com/sparkfun/SparkFun_BNO080_Arduino_Library/issues/16
    //=================================
    delay(100); //  Wait for BNO to boot
    // Start i2c and BNO080
    Wire.flush();   // Reset I2C
    myIMU.begin(BNO080_DEFAULT_ADDRESS, Wire);
    Wire.begin(_sda, _scl);
    //=================================
    Serial.printf("Initializing BNO08x...");
    // imuINTPin is used as an active-low interrupt. .begin configures the pinMode as INPUT_PULLUP
    if (myIMU.begin(BNO080_DEFAULT_ADDRESS, Wire) == false)
    {
        Serial.println("BNO080 not detected at default I2C address. Check your jumpers and the hookup guide. Freezing...");
        while (1);
    }

    Wire.setClock(400000); //Increase I2C data rate to 400kHz  
    myIMU.enableDebugging(); // Uncomment this line to enable debug messages on Serial
    myIMU.enableAccelerometer(50);    //We must enable the accel in order to get MEMS readings even if we don't read the reports.
    myIMU.enableRawAccelerometer(50); //Send data update every 50ms
    myIMU.enableGyro(50);
    myIMU.enableRawGyro(50);
    myIMU.enableMagnetometer(50);
    myIMU.enableRawMagnetometer(50);
}

void BNO08x::printIMUData()
{
    if (myIMU.dataAvailable() == true)
    {
        int x = myIMU.getRawAccelX();
        int y = myIMU.getRawAccelY();
        int z = myIMU.getRawAccelZ();

        Serial.printf("Acceleration: [x: %d, y: %d, z: %d]\n", x, y, z);

        int gx = myIMU.getRawGyroX();
        int gy = myIMU.getRawGyroY();
        int gz = myIMU.getRawGyroZ();

        Serial.printf("Gyro: [x: %d, y: %d, z: %d]\n", gx, gy, gz);

        int mx = myIMU.getRawMagX();
        int my = myIMU.getRawMagY();
        int mz = myIMU.getRawMagZ();

        Serial.printf("Magnetometer: [x: %d, y: %d, z: %d]\n", gx, gy, gz);
    }
}