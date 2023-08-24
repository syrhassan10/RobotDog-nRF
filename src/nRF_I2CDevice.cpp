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

    int ret = i2c_write_read_dt(&servo_driver_i2c1, write_buf, num_write,read_buf,num_read);
    if(ret != 0){
	    printk("Failed to write/read I2C device address %x ", servo_driver_i2c1.addr);
    }
    return ret;

}

int nRF_I2CDevice::write_i2c(const uint8_t *buf, uint32_t num_bytes)
{
    int ret = i2c_write_dt(&servo_driver_i2c1, buf, num_bytes);
    if(ret != 0){
        printk("Failed to write to I2C device address %x", servo_driver_i2c1.addr);
    }
    return ret;

}

int nRF_I2CDevice::read_i2c(uint8_t *buf, uint32_t num_bytes)
{
    int ret = i2c_read_dt(&servo_driver_i2c1, buf, num_bytes);
    if(ret != 0){
        printk("Failed to read from I2C device address %x", servo_driver_i2c1.addr);
    }
    return ret;
}
