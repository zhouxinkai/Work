#!/bin/bash
rmmod s3c24xx_sensor.ko
rmmod s3c24xx_pwm.ko
rm -f *.ko sensor_test
