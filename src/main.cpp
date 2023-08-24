/*
 * Copyright (c) 2016 Intel Corporation
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Sample app to demonstrate PWM.
 */
#include <stdlib.h> 
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "nRF_I2CDevice.h"
/*
#define I2C0_NODE DT_NODELABEL(motor_driver1)
#define I2C0_NODE2 DT_NODELABEL(motor_driver2)
static const struct i2c_dt_spec dev_i2c = I2C_DT_SPEC_GET(I2C0_NODE);
*/
nRF_I2CDevice *servo_driver1 = new nRF_I2CDevice();

int main(void)
{
	
	if (!device_is_ready(servo_driver1->servo_driver_i2c1.bus)) {
		printk("I2C bus %s is not ready!\n\r",servo_driver1->servo_driver_i2c1.bus->name);
		return 1;
	}	
	printk("Hello World! %s\n", CONFIG_BOARD);
	

	return 1;
}
