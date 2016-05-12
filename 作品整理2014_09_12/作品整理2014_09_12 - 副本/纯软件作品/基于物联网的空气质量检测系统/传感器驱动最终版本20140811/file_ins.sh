#!bin/sh
chmod 0777 *.ko sensor_test
insmod s3c24xx_sensor.ko
insmod s3c24xx_pwm.ko
mknod /dev/sensor c 232 0
mknod /dev/pwm c 233 0
