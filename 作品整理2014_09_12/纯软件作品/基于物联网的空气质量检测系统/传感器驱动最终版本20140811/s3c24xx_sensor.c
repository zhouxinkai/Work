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

#define DEVICE_NAME     "sensor"  /* ����ģʽ��ִ�С�cat /proc/devices����������豸���� */
#define SENSOR_MAJOR       232     /* ���豸�� */
int i=0;


/* ����ָ��sensor���õ�GPIO���� */
static unsigned long led_table [] = {
//    S3C2410_GPG14,
    S3C2410_GPG14,
    S3C2410_GPB6,
    S3C2410_GPB7,
    S3C2410_GPB8,
};

/* ����ָ��GPIO���ŵĹ��ܣ���� */
static unsigned int led_cfg_table [] = {
//    S3C2410_GPG14_INP,
    S3C2410_GPG14_INP,
    S3C2410_GPB6_OUTP,
    S3C2410_GPB7_OUTP,
    S3C2410_GPB8_OUTP,
};



/* Ӧ�ó�����豸�ļ�/dev/ledsִ��open(...)ʱ��
 * �ͻ����s3c24xx_sensor_open����
 */
static int s3c24xx_sensor_open(struct inode *inode, struct file *file)
{
    
   // ����GPIO���ŵĹ��ܣ���������sensor���漰��GPIO������Ϊ���빦��
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
//�ڽ��������͵����ݹ�����ַ���ʱ��sprintf ��ǿ���ܺ��ٻ�����ʧ����
//����sprintf ��printf ���÷��ϼ���һ����ֻ�Ǵ�ӡ��Ŀ�ĵز�ͬ���ѣ�
//ǰ�ߴ�ӡ���ַ����У�������ֱ���������������
/*    a=s3c2410_gpio_getpin(led_table[i]);
    if(a==(1<<offs))
        *buff='H';
    else *buff='L';*/
    return 0;
}
/* ����ṹ���ַ��豸��������ĺ���
 * ��Ӧ�ó�������豸�ļ�ʱ�����õ�open��read��write�Ⱥ�����
 * ���ջ��������ṹ��ָ���Ķ�Ӧ����
 */
static struct file_operations s3c24xx_sensor_fops = {
    .owner  =   THIS_MODULE,    /* ����һ���꣬�������ģ��ʱ�Զ�������__this_module���� */
    .open   =   s3c24xx_sensor_open,     
    .read   =   s3c24xx_sensor_read,
};

/*
 * ִ�С�insmod s3c24xx_sensor.ko������ʱ�ͻ�����������
 */
static int __init s3c24xx_sensor_init(void)
{
    int ret;

    /* ע���ַ��豸��������
     * ����Ϊ���豸�š��豸���֡�file_operations�ṹ��
     * ���������豸�žͺ;����file_operations�ṹ��ϵ�����ˣ�
     * �������豸ΪSENSOR_MAJOR���豸�ļ�ʱ���ͻ����s3c24xx_sensor_fops�е���س�Ա����
     * SENSOR_MAJOR������Ϊ0����ʾ���ں��Զ��������豸��
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
 * ִ�С�rmmod s3c24xx_sensor.ko������ʱ�ͻ����������� 
 */
static void __exit s3c24xx_sensor_exit(void)
{
    /* ж���������� */
    unregister_chrdev(SENSOR_MAJOR, DEVICE_NAME);
}

/* ������ָ����������ĳ�ʼ��������ж�غ��� */
module_init(s3c24xx_sensor_init);
module_exit(s3c24xx_sensor_exit);

/* �������������һЩ��Ϣ�����Ǳ���� */
MODULE_AUTHOR("http://www.100ask.net");             // �������������
MODULE_DESCRIPTION("S3C2410/S3C2440 LED Driver");   // һЩ������Ϣ
MODULE_LICENSE("GPL");                              // ��ѭ��Э��
