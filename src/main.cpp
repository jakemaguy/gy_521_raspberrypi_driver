#include <iostream>
#include "i2c/driver.h"

int main()
{
    i2cDriver i2c;
    while(true)
    {
        i2c.getAccelMeasurements();
    }
    return 0;
}