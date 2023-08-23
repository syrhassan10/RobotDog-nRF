/*
 * Copyright (c) 2016 Intel Corporation
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Sample app to demonstrate PWM.
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/drivers/i2c.h>


#define I2C0_NODE DT_NODELABEL(motor_driver1)
#define I2C0_NODE2 DT_NODELABEL(motor_driver2)
static const struct i2c_dt_spec dev_i2c = I2C_DT_SPEC_GET(I2C0_NODE);

void main(void)
{

	if (!device_is_ready(dev_i2c.bus)) {
		printk("I2C bus %s is not ready!\n\r",dev_i2c.bus->name);
		return;
	}
	
	uint8_t config[2] = {0x03,0x8C};
	
	int ret = i2c_write_dt(&dev_i2c, config, sizeof(config));
	
	if(ret != 0){
		printk("Failed to write to I2C device address %x at reg. %x n", dev_i2c.addr,config[0]);
	}
	
	printk("Hello World! %s\n", CONFIG_BOARD);

}
