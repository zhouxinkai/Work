#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/irq.h>
#include <mach/regs-gpio.h>
#include <mach/hardware.h>

#include <linux/time.h>
#include <linux/jiffies.h>
#include <linux/param.h>
//#include <unistd.h>
//#include "irq.h"
//#include "regs-gpio.h"
//#include "hardware.h"

#define DEVICE_NAME     "sensor"  /* 加载模式后，执行”cat /proc/devices”命令看到的设备名称 */
#define SENSOR_MAJOR       232     /* 主设备号 */
int i=0;


/* 用来指定sensor所用的GPIO引脚 */
static unsigned long led_table [] = {
//    S3C2410_GPG14,
    S3C2410_GPG14,
    S3C2410_GPB6,
    S3C2410_GPB7,
    S3C2410_GPB8,
};

/* 用来指定GPIO引脚的功能：输出 */
static unsigned int led_cfg_table [] = {
//    S3C2410_GPG14_INP,
    S3C2410_GPG14_INP,
    S3C2410_GPB6_OUTP,
    S3C2410_GPB7_OUTP,
    S3C2410_GPB8_OUTP,
};



/* 应用程序对设备文件/dev/leds执行open(...)时，
 * 就会调用s3c24xx_sensor_open函数
 */
static int s3c24xx_sensor_open(struct inode *inode, struct file *file)
{
    
   // 设置GPIO引脚的功能：本驱动中sensor所涉及的GPIO引脚设为输入功能
     s3c2410_gpio_cfgpin(led_table[i], led_cfg_table[i]);
     return 0;
}

static ssize_t s3c24xx_sensor_read(struct file *filp,char __user *buff,size_t count,loff_t *offp)
{
	unsigned long begin=0,end=0;
    long usec=0;
//  unsigned int a;
	unsigned long offs = S3C2410_GPIO_OFFSET(led_table[i]);
	while(s3c2410_gpio_getpin(led_table[i])==(1<<offs));
	//begin=millis();
	begin=jiffies;
	while(!(s3c2410_gpio_getpin(led_table[i])==(1<<offs)));
	//end=millis();
	end=jiffies;	
	
	usec=(long)end-(long)begin;
    usec=usec*1000000/HZ;
	printk("usec=%d\n",usec);
	//*buff=*((char *)(&usec));
	sprintf(buff,"%d",usec);
//在将各种类型的数据构造成字符串时，sprintf 的强大功能很少会让你失望。
//由于sprintf 跟printf 在用法上几乎一样，只是打印的目的地不同而已，
//前者打印到字符串中，后者则直接在命令行上输出
/*    a=s3c2410_gpio_getpin(led_table[i]);
    if(a==(1<<offs))
        *buff='H';
    else *buff='L';*/
    return 0;
}
/* 这个结构是字符设备驱动程序的核心
 * 当应用程序操作设备文件时所调用的open、read、write等函数，
 * 最终会调用这个结构中指定的对应函数
 */
static struct file_operations s3c24xx_sensor_fops = {
    .owner  =   THIS_MODULE,    /* 这是一个宏，推向编译模块时自动创建的__this_module变量 */
    .open   =   s3c24xx_sensor_open,     
    .read   =   s3c24xx_sensor_read,
};

/*
 * 执行“insmod s3c24xx_sensor.ko”命令时就会调用这个函数
 */
static int __init s3c24xx_sensor_init(void)
{
    int ret;

    /* 注册字符设备驱动程序
     * 参数为主设备号、设备名字、file_operations结构；
     * 这样，主设备号就和具体的file_operations结构联系起来了，
     * 操作主设备为SENSOR_MAJOR的设备文件时，就会调用s3c24xx_sensor_fops中的相关成员函数
     * SENSOR_MAJOR可以设为0，表示由内核自动分配主设备号
     */
    ret = register_chrdev(SENSOR_MAJOR, DEVICE_NAME, &s3c24xx_sensor_fops);
    if (ret < 0) {
      printk(DEVICE_NAME " can't register major number\n");
      return ret;
    }
    
    printk(DEVICE_NAME " sensor module initialized\n");
    return 0;
}

/*
 * 执行”rmmod s3c24xx_sensor.ko”命令时就会调用这个函数 
 */
static void __exit s3c24xx_sensor_exit(void)
{
    /* 卸载驱动程序 */
    unregister_chrdev(SENSOR_MAJOR, DEVICE_NAME);
}

/* 这两行指定驱动程序的初始化函数和卸载函数 */
module_init(s3c24xx_sensor_init);
module_exit(s3c24xx_sensor_exit);

/* 描述驱动程序的一些信息，不是必须的 */
MODULE_AUTHOR("http://www.100ask.net");             // 驱动程序的作者
MODULE_DESCRIPTION("S3C2410/S3C2440 LED Driver");   // 一些描述信息
MODULE_LICENSE("GPL");                              // 遵循的协议
