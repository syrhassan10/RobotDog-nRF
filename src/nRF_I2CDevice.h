
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/drivers/i2c.h>

class nRF_I2CDevice {

public:

nRF_I2CDevice();

static struct i2c_dt_spec servo_driver_i2c1;
static struct i2c_dt_spec servo_driver_i2c2;

};