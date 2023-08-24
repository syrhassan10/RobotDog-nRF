#include "nRF_I2CDevice.h"



#define I2C0_NODE DT_NODELABEL(motor_driver1)
#define I2C1_NODE DT_NODELABEL(motor_driver2)

nRF_I2CDevice::nRF_I2CDevice()
{
    servo_driver_i2c1 = I2C_DT_SPEC_GET(I2C0_NODE);
    servo_driver_i2c2 = I2C_DT_SPEC_GET(I2C1_NODE);
}


int nRF_I2CDevice::write_read_i2c(const void *write_buf, size_t num_write, void *read_buf, size_t num_read)
{
    
    return i2c_write_read_dt(&servo_driver_i2c1, write_buf, num_write,read_buf,num_read);

}