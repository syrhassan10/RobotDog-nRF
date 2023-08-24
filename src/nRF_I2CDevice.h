
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/drivers/i2c.h>

class nRF_I2CDevice {

public:

nRF_I2CDevice();

struct i2c_dt_spec servo_driver_i2c1;
struct i2c_dt_spec servo_driver_i2c2;


int write_read_i2c(const void *write_buf, size_t num_write, void *read_buf, size_t num_read);
int write_i2c(const uint8_t *buf, uint32_t num_bytes);
int read_i2c(uint8_t *buf, uint32_t num_bytes);


};