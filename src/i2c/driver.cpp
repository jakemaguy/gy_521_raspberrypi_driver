#include <iostream>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "driver.h"

i2cDriver::i2cDriver()
{   
    int i2c_handle;
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