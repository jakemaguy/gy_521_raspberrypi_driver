#include <iostream>
#include <unistd.h>
#include "i2c/driver.h"
#include "gui/menu.h"

int main()
{
    i2cDriver i2c;

    while (true)
    {
        i2c.getAccelMeasurements();
	sleep(1);
    }
    return 0;
}
