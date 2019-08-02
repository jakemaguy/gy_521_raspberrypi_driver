#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <linux/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "driver.h"

i2cDriver::i2cDriver()
{
    if ((i2c_handle = open("/dev/i2c-1", O_RDWR)) < 0)
    {
        std::cout << "Failed to open bus\n";
    }

    if (ioctl(i2c_handle, I2C_SLAVE, I2C_ADDR) < 0)
    {
        std::cout << "Failed\n";
    }
    
    //I2C connection has been established here
    // Setting Sleep = 0
    char buf[2] = {PWR_MGMT_1, 0x00};
    write(i2c_handle,buf,2);
}

i2cDriver::~i2cDriver()
{   

}

void i2cDriver::getAccelMeasurements()
{
    __u8 xGyroRegH = 0x43;
    __u8 xGyroRegL = 0x44;
    char buf[3];
    buf[0] = 0x3B;
    write(i2c_handle, buf, 1);

    read(i2c_handle, buf, 2);

    float x_meas = (float)(buf[0] << 8) + buf[1];
    std::cout << x_meas << "\n";
}
