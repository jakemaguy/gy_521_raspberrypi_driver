#include <iostream>
#include <unistd.h>
#include "i2c/driver.h"

int main()
{
    i2cDriver i2c;
    while(true)
    {
        i2c.getAccelMeasurements();
	sleep(0.5);
    }
    return 0;
}
