ifeq ($(KERNELRELEASE),)
#在Linux源码根目录下的Makefile编译内核时，KERNELRELEASE宏会被定义
KERNELDIR ?=/home/yeshang/src/EmbedSky/linux-2.6.30.4/

PWD := $(shell pwd)
#这个变量是我们在后面指代我们要编译的驱动程序源码所在的位置。
modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
#	arm-linux-gcc sensor_test.c -L /lib -lm -o sensor_test
	arm-linux-gcc sensor_test.c  -lm -o sensor_test
#-C 选项的作用是指将当前工作目录转移到你所指定的位置。
#“M=”选项的作用是，当用户需要以某个内核为基础编译一个外部模块的话，
#需要在make modules 命令中加入“M=dir”，程序会自动到你所指定的dir目录中查找驱动程序源码，
#将其编译，生成KO文件。 
#modules_install:
#	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install
#这个命令是模块的安装

clean:
	rm -rf *.o *~ core .depend .*.cmd  *.mod.c .tmp_versions *.order Module*  
realclean:
	rm -rf *.o *~ core .depend .*.cmd  *.mod.c .tmp_versions *.order Module*  *.ko sensor_test

.PHONY: modules  clean realclean

else
#    obj-m := s3c24xx_leds.o
    obj-m := s3c24xx_sensor.o
     obj-m += s3c24xx_pwm.o
endif
