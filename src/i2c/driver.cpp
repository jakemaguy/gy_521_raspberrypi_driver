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
}

i2cDriver::~i2cDriver()
{   

}

void i2cDriver::getAccelMeasurements()
{
    __u16 xGyro;
    __u8 xGyroReg = 0x43;
    char buf[10];
    buf[0] = I2C_ADDR;
    buf[1] = xGyroReg;

    write(i2c_handle, buf, 1);
    
    buf[0] = xGyroReg;
    buf[1] = xGyroReg;

    read(i2c_handle, buf, 2);

    float x_meas = ((float)buf[1] >> 8) + (float)buf[0];
    std::cout << x_meas << "\n";
}