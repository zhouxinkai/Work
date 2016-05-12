/*************************************

NAME:EmbedSky_pwm.c
COPYRIGHT:www.embedsky.net

*************************************/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/poll.h>
#include <asm/irq.h>
#include <asm/io.h>
#include <linux/interrupt.h>
#include <asm/uaccess.h>
#include <mach/regs-gpio.h>
#include <mach/hardware.h>
#include <plat/regs-timer.h>
#include <mach/regs-irq.h>
#include <asm/mach/time.h>
#include <linux/clk.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/miscdevice.h>

#define DEVICE_NAME     "pwm"		//设备名称
#define PWM_MAJOR       233     /* 主设备号 */

//static struct semaphore lock;

static int tq2440_pwm_open(struct inode *inode, struct file *file)
{
	s3c2410_gpio_cfgpin(S3C2410_GPB0, S3C2410_GPB0_TOUT0);	//set GPB0 as tout0, pwm output
	return 0;
}


static int tq2440_pwm_close(struct inode *inode, struct file *file)
{
//	up(&lock);
	return 0;
}


static int tq2440_pwm_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned long tcfg0;
	unsigned long tcfg1;
	unsigned long tcntb;
	unsigned long tcmpb;
	unsigned long tcon;

	if(cmd <= 0)		//如果输入的参数小于或等于0的话，就让蜂鸣器停止工作
	{
		s3c2410_gpio_cfgpin(S3C2410_GPB0, S3C2410_GPB0_OUTP);
		s3c2410_gpio_setpin(S3C2410_GPB0, 0);
		//这里又恢复GPB0口为IO口输出功能，由原理图可知直接给低电平可让蜂鸣器停止工作
	}
	else
	{
		struct clk *clk_p;
		unsigned long pclk;

		//set GPB0 as tout0, pwm output
//		s3c2410_gpio_cfgpin(S3C2410_GPB0, S3C2410_GPB0_TOUT0);

		tcon = __raw_readl(S3C2410_TCON);
		tcfg1 = __raw_readl(S3C2410_TCFG1);
		tcfg0 = __raw_readl(S3C2410_TCFG0);

		//prescaler = 50
		tcfg0 &= ~S3C2410_TCFG_PRESCALER0_MASK;
		tcfg0 |= (50 - 1); 

		//mux = 1/16
		tcfg1 &= ~S3C2410_TCFG1_MUX0_MASK;
		tcfg1 |= S3C2410_TCFG1_MUX0_DIV16;

		__raw_writel(tcfg1, S3C2410_TCFG1);
		__raw_writel(tcfg0, S3C2410_TCFG0);

		clk_p = clk_get(NULL, "pclk");
		pclk  = clk_get_rate(clk_p);	//从系统平台时钟队列中获取pclk的时钟频率，在include/linux/clk.h中定义
//      printk("pclk=%d\n",pclk);
//      打印之后pclk=50000000HZ=50MHZ
		tcntb  = (pclk/50/16)/cmd;		//则PWM的周期为1/cmd，单位为秒
		//tcntb  = (pclk/50/16)*cmd;		//则PWM的周期为cmd
//		tcmpb = tcntb>>1;				//tcmpb=tcntb/2,则PWM占空比永远为50%
		tcmpb = tcntb/arg;				//则PWM占空比为1-1/arg,低电平所占比列为1/arg

		__raw_writel(tcntb, S3C2410_TCNTB(0));
		__raw_writel(tcmpb, S3C2410_TCMPB(0));
			
		tcon &= ~0x1f;
//		tcon |= 0xb;		//start timer,且引脚初始为低电平
       	tcon |= 0xf;		//start timer,且引脚初始为高电平
		
		__raw_writel(tcon, S3C2410_TCON);

		tcon &= ~2;
		__raw_writel(tcon, S3C2410_TCON);
	}

	return 0;
}


static struct file_operations dev_fops = {
    .owner		=   THIS_MODULE,
    .open		=   tq2440_pwm_open,
    .release	=   tq2440_pwm_close, 
    .ioctl		=   tq2440_pwm_ioctl,
};

/*static struct miscdevice misc = {
	.minor	= MISC_DYNAMIC_MINOR,
	.name	= DEVICE_NAME,
	.fops	= &dev_fops,
};*/

static int __init dev_init(void)
{
/*	int ret;

	init_MUTEX(&lock);
	ret = misc_register(&misc);

	printk (DEVICE_NAME" initialized\n");
    	return ret;*/
    int ret;

    /* 注册字符设备驱动程序
     * 参数为主设备号、设备名字、file_operations结构；
     * 这样，主设备号就和具体的file_operations结构联系起来了，
     * 操作主设备为SENSOR_MAJOR的设备文件时，就会调用s3c24xx_sensor_fops中的相关成员函数
     * SENSOR_MAJOR可以设为0，表示由内核自动分配主设备号
     */
    ret = register_chrdev(PWM_MAJOR, DEVICE_NAME, &dev_fops);
    if (ret < 0) {
      printk(DEVICE_NAME " can't register major number\n");
      return ret;
    }
    
    printk(DEVICE_NAME " pwm module initialized\n");
    return 0;
}

static void __exit dev_exit(void)
{
//	misc_deregister(&misc);
	unregister_chrdev(PWM_MAJOR, DEVICE_NAME);
}

module_init(dev_init);
module_exit(dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("www.embedsky.net");
MODULE_DESCRIPTION("PWM Drivers for EmbedSky SKY2440/TQ2440 Board");
