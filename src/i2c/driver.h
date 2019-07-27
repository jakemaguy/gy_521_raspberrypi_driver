#include <iostream>

#define I2C_ADDR 0x68
#define PWR_MGMT_1 0x6B

class i2cDriver
{
    public:
        i2cDriver();
        ~i2cDriver();

        void getAccelMeasurements();
    private:
        int i2c_handle;
};
