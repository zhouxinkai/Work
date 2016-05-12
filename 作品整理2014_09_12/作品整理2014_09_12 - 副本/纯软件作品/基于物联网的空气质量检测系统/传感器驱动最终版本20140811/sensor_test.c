#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <math.h>

//enum edge{UP,DOWN,ERROR};
//unsigned long pulseIn();
unsigned long millis();
//enum edge check_sensor();
void usage(char *exename);
int pwm(int argc,char **argv);
struct timeval time_us;

unsigned long duration=0;		//低电平持续时间
unsigned long starttime=0;
unsigned long sampletime_us = 30000000;//sampe 30s ;
unsigned long lowpulseoccupancy = 0;	//低电平占有时间
long double ratio = 0;						//低电平占有时间与总时间的比例
long double concentration = 0;				//浓度
int fd_sen = -1,fd_pwm = -1;
char sen[10];

int main(int argc, char **argv)
{
    int count=argc;
    char **vector=argv;
    if(pwm(count,vector)<0) exit(1);
    fd_sen = open("/dev/sensor", 0);  // 打开设备
    if (fd_sen < 0) {
        printf("Can't open /dev/sensor\n");
        return -1;
    }
	starttime = millis();//get the current time;
	while(0)
	{
		read(fd_sen,sen,1);
		if(sen[0]=='H')   printf("sensor input is H\n");
		if(sen[0]=='L')		printf("sensor input is L\n");
	}
    while(1)
    {
		read(fd_sen,sen,10);
    	duration = strtoul(sen,0,0);
//		duration =pulseIn();
		lowpulseoccupancy +=duration;
		  if ((millis()-starttime) > sampletime_us)//if the sampel time == 30s
			  {
				ratio = lowpulseoccupancy/(sampletime_us*1.0);  // Integer percentage 0=>100
				concentration = 1.1*pow(ratio,3.0)-3.8*pow(ratio,2.0)+520*ratio+0.62; // using spec sheet curve
				printf("lowpulseoccupancy is:%d\n",lowpulseoccupancy);
				printf("ratio is:%f\n",ratio);
				printf("concentration is:%f\n",concentration);
				lowpulseoccupancy = 0;
				starttime = millis();
			  }
    }
	close(fd_pwm);
    close(fd_sen);
    return 0;
}

unsigned long millis()
{
	unsigned long t;
	if(gettimeofday(&time_us,NULL)<0)
	{
		printf("Can't get the current time");
	}
	t=time_us.tv_sec*1000000+time_us.tv_usec;
    return t;
}

/*unsigned long pulseIn()
{
	unsigned long begin=0,end=0;
    printf("1111111111111111111111111\n");
	while(!(check_sensor()==DOWN));    
	begin=millis();
	while(!(check_sensor()==UP));	  
	end=millis();
    printf("2222222222222222222222222222\n");
	return (end-begin);
}

enum edge check_sensor()
{
    read(fd_sen,sen,1);
    if(sen[0]=='H') 
    {   
//      usleep(5);
        read(fd_sen,sen,1);
        if(sen[0]=='L')
            return DOWN;
        else return ERROR;
    }
    //read(fd_sen,sen,1);
    else
    {
        if(sen[0]=='L')
        {
//        usleep(5);
            read(fd_sen,sen,1);
            if(sen[0]=='H')
                return UP;
            else return ERROR;
        }
    }
}
*/

void usage(char *exename)
{
    printf("Usage:\n");
    printf("    %s <cmd> <arg>\n", exename);
    printf("    PWM period=1/cmd(0 is stop,unit is s),  PWM duty ratio=1-1/arg\n");		//cmd=0表示停止工作
}
int pwm(int argc,char **argv)
{
    unsigned long cmd,arg;
    
    if (argc != 3)
        goto err;
        
	//fd = open("/dev/leds", 0);  // 打开设备
    //打开蜂鸣器设备
     fd_pwm = open("/dev/pwm", 0);
     if(fd_pwm < 0)
     {
         printf("Open PWM Device Faild!\n");
         exit(1);
     }
	cmd=strtoul(argv[1],0,0);
	arg=strtoul(argv[2],0,0);
    ioctl(fd_pwm, cmd,arg);
    return 0;

    
err:
    if (fd_pwm > 0) 
        close(fd_pwm);
    usage(argv[0]);
	    return -1;
}

