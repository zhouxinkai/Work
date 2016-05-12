#include   <stdio.h>      
#include   <stdlib.h>    
#include   <unistd.h>      
#include   <sys/types.h>  
#include   <sys/stat.h>   
#include   <fcntl.h>     
#include   <termios.h>   
#include   <errno.h>     
#include   <string.h> 
#define DEVICE_PORT "/dev/ttySAC1"
//FILE *fp;                                       //记录文件描述符
/*  GPRMC                   */
typedef struct gps_info
{
    char utc_time[30];                             //UTC时间,hhmmss.sss(时分秒.毫秒)格式
    char status;                                    //定位状态,A=有效定位,V无效定位
    float latitude_value;                            //纬度ddmm.mmmm(度分)格式(前面的0也将被传输)
    char latitude;                                      //纬度半球N(北半球)S(南半球)
    float  longtitude_value;                                //经度dddmm.mmmm
    char  longtitude;                                     //经度半球E东经 W西经  
    float speed;                                           //地面素率(000.0~999.9节)
    float  azimuth_angle;                                   //地面导航(000.0~359.9度,以正北为参考基准)
    char  utc_data[30];                                   //UTC日期 ddmmyy(日年月格式)
    float declination;                                    //偏磁角(000.0~180.0度)
    char  dectude;                                        //偏此角方相E动W西
}GPS_INFO1;

GPS_INFO1 GPS_INFO;




/*   打开串口                    */
int open_port(int fd)
{
    fd =open(DEVICE_PORT,O_RDWR|O_NOCTTY|O_NDELAY);
    if(fd==-1)
    {
	perror("open");
	exit(1);
    }
    /* 恢复串口为阻塞状态   */
    if(fcntl(fd,F_SETFL,0)<0)
	printf("fcntl failed!\n");
    else
	printf("fcntl=%d\n",fcntl(fd,F_SETFL,0));
    /*   测试是否为终端设备                       */
    if(isatty(STDIN_FILENO)==0)
	printf("standard input is not a terminal device\n");
    else
	printf("isatty sucess!\n");
    printf("fd-open=%d\n",fd);
    return fd;
}
/*    设置端口                           */
int set_opt(int fd,int nSpeed,int nBits,char nEvent,int nStop)
{
    struct termios newtio,oldtio;
    /* 取得现有串口属性                 */
    if(tcgetattr(fd,&oldtio)!=0)
    {
	perror("SetupSerial 1");
	return -1;
    }
    bzero(&newtio,sizeof(newtio));
    newtio.c_lflag|=ICANON;  //设置成规范模式 以行读取
    /*  原始模式                   */
    /*newtio.c_iflag &=~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
      newtio.c_oflag &=~OPOST;
      newtio.c_lflag &=~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);*/
    /*设置字符大小             */
    newtio.c_cflag |= CLOCAL |CREAD;
    newtio.c_cflag &= ~CSIZE;

    /*    设置数据位      */
    switch(nBits)
    {
	case 7:
	    newtio.c_cflag |=CS7; break;
	case 8:
	    newtio.c_cflag |=CS8; break;
    }
    /*    设置 奇偶校验位                */
    switch(nEvent)
    {
	case 'O':
	    newtio.c_cflag |=PARENB;
	    newtio.c_cflag |=PARODD;
	    newtio.c_iflag|=INPCK ;
	    break;
	case 'E':
	    newtio.c_iflag |= INPCK ;
	    newtio.c_cflag |= PARENB;
	    newtio.c_cflag &=~PARODD;
	    break;
	case 'N':
	    newtio.c_cflag &= ~PARENB;
	    break; 
    }
    switch(nSpeed)
    {
	case 2400:
	    cfsetispeed(&newtio,B2400);
	    cfsetospeed(&newtio,B2400);
	    break;
	case 4800:
	    cfsetispeed(&newtio,B4800);
	    cfsetospeed(&newtio,B4800);
	    break;
	case 9600:
	    cfsetispeed(&newtio,B9600);
	    cfsetospeed(&newtio,B9600);
	    break;
	case 115200:
	    cfsetispeed(&newtio,B115200);
	    cfsetospeed(&newtio,B115200);
	    break;
defult:
	    cfsetispeed(&newtio,B115200);
	    cfsetospeed(&newtio,B115200);
	    break;
    }
    /*  设置停止位*/
    if(nStop==1)
	newtio.c_cflag &= ~CSTOPB;
    else if(nStop==2)
	newtio.c_cflag |= CSTOPB;
    /*   设置等待时间和接收最小字符      */
    newtio.c_cc[VTIME]=0;
    newtio.c_cc[VMIN]=0;
    /*  处理未接收字符          */
    tcflush(fd,TCIFLUSH);
    /* 激活新配置          */
    if((tcsetattr(fd,TCSANOW,&newtio))!=0)
    {
	perror("come set error");
	return -1;
    }
    printf("set done\n");
    return 0;
}

/* 读串口                  */
void read_port(int fd)
{
    int nread;
    char buff[512];
    fd_set rd;
    FD_ZERO(&rd);
    FD_SET(fd,&rd);
    while(FD_ISSET(fd,&rd))
    {
	if(select(fd+1,&rd,NULL,NULL,NULL)<0)
	{
	    perror("select");
	    exit(1);
	}
	else 
	{

	    while((nread=read(fd,buff,512))>0)
/*注意，在对串口进行读取操作的时候，如果是使用的RAW模式，每个read系统调用
将返回当前串行输入缓冲区中存在的字节数。如果没有数据，将会一致阻塞到有字符达
到或者间隔时钟到期，或者发生错误。如果想使read函数在没有数据的时候立即返回
则可以使用fcntl函数来设置文件访问属性。例如：
fcntl(fd, F_SETFL, FNDELAY);  
这样设置后，当没有可读取的数据时，read函数立即返回0。*/
	    {
		buff[nread]='\0';
		char *p;
		int n,num=0;

		if((p=strstr(buff,"$GPRMC"))!=NULL)
//char * strstr（char *1,char *s2）,返回s1中第一次出现子串s2位置的指针
		{
		    
//		    printf("\n\nbuff = %s\n\n",buff);
		    for(n=0;n<strlen(p);n++)
		    {
			printf("%d\n",n);
			if(p[n]=='\n')
			    p[n]='\0';
		    }         
		    printf("%s\n",p);
		    sscanf(p,"$GPRMC,%*[^,],%*c,%f,%*c,%f,%*c",&GPS_INFO.latitude_value,&GPS_INFO.longtitude_value);
/*加了星号 (*) 表示跳过此数据不读入. (也就是不把此数据读入p中)
%[^a] 匹配非a的任意字符，并且停止读入
%*[width] [{h | l | I64 | L}]type 表示满足该条件的被过滤掉，不会向目标参数中写入值*/
		    printf("%f %f\n",GPS_INFO.latitude_value,GPS_INFO.longtitude_value);

		}
	    }
	}
    }

}

int main()
{
    int fd;
    int i;

    if((fd=open_port(fd))<0)
    {
	perror("open");
	exit(1);
    }
    if(i=set_opt(fd,9600,8,'N',1)<0)
    {
	perror("set_opt error");
	exit(1);
    }

    read_port(fd);

}
