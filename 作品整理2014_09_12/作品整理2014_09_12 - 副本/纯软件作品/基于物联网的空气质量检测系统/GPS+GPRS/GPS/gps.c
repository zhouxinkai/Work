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
//FILE *fp;                                       //��¼�ļ�������
/*  GPRMC                   */
typedef struct gps_info
{
    char utc_time[30];                             //UTCʱ��,hhmmss.sss(ʱ����.����)��ʽ
    char status;                                    //��λ״̬,A=��Ч��λ,V��Ч��λ
    float latitude_value;                            //γ��ddmm.mmmm(�ȷ�)��ʽ(ǰ���0Ҳ��������)
    char latitude;                                      //γ�Ȱ���N(������)S(�ϰ���)
    float  longtitude_value;                                //����dddmm.mmmm
    char  longtitude;                                     //���Ȱ���E���� W����  
    float speed;                                           //��������(000.0~999.9��)
    float  azimuth_angle;                                   //���浼��(000.0~359.9��,������Ϊ�ο���׼)
    char  utc_data[30];                                   //UTC���� ddmmyy(�����¸�ʽ)
    float declination;                                    //ƫ�Ž�(000.0~180.0��)
    char  dectude;                                        //ƫ�˽Ƿ���E��W��
}GPS_INFO1;

GPS_INFO1 GPS_INFO;




/*   �򿪴���                    */
int open_port(int fd)
{
    fd =open(DEVICE_PORT,O_RDWR|O_NOCTTY|O_NDELAY);
    if(fd==-1)
    {
	perror("open");
	exit(1);
    }
    /* �ָ�����Ϊ����״̬   */
    if(fcntl(fd,F_SETFL,0)<0)
	printf("fcntl failed!\n");
    else
	printf("fcntl=%d\n",fcntl(fd,F_SETFL,0));
    /*   �����Ƿ�Ϊ�ն��豸                       */
    if(isatty(STDIN_FILENO)==0)
	printf("standard input is not a terminal device\n");
    else
	printf("isatty sucess!\n");
    printf("fd-open=%d\n",fd);
    return fd;
}
/*    ���ö˿�                           */
int set_opt(int fd,int nSpeed,int nBits,char nEvent,int nStop)
{
    struct termios newtio,oldtio;
    /* ȡ�����д�������                 */
    if(tcgetattr(fd,&oldtio)!=0)
    {
	perror("SetupSerial 1");
	return -1;
    }
    bzero(&newtio,sizeof(newtio));
    newtio.c_lflag|=ICANON;  //���óɹ淶ģʽ ���ж�ȡ
    /*  ԭʼģʽ                   */
    /*newtio.c_iflag &=~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
      newtio.c_oflag &=~OPOST;
      newtio.c_lflag &=~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);*/
    /*�����ַ���С             */
    newtio.c_cflag |= CLOCAL |CREAD;
    newtio.c_cflag &= ~CSIZE;

    /*    ��������λ      */
    switch(nBits)
    {
	case 7:
	    newtio.c_cflag |=CS7; break;
	case 8:
	    newtio.c_cflag |=CS8; break;
    }
    /*    ���� ��żУ��λ                */
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
    /*  ����ֹͣλ*/
    if(nStop==1)
	newtio.c_cflag &= ~CSTOPB;
    else if(nStop==2)
	newtio.c_cflag |= CSTOPB;
    /*   ���õȴ�ʱ��ͽ�����С�ַ�      */
    newtio.c_cc[VTIME]=0;
    newtio.c_cc[VMIN]=0;
    /*  ����δ�����ַ�          */
    tcflush(fd,TCIFLUSH);
    /* ����������          */
    if((tcsetattr(fd,TCSANOW,&newtio))!=0)
    {
	perror("come set error");
	return -1;
    }
    printf("set done\n");
    return 0;
}

/* ������                  */
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
/*ע�⣬�ڶԴ��ڽ��ж�ȡ������ʱ�������ʹ�õ�RAWģʽ��ÿ��readϵͳ����
�����ص�ǰ�������뻺�����д��ڵ��ֽ��������û�����ݣ�����һ�����������ַ���
�����߼��ʱ�ӵ��ڣ����߷������������ʹread������û�����ݵ�ʱ����������
�����ʹ��fcntl�����������ļ��������ԡ����磺
fcntl(fd, F_SETFL, FNDELAY);  
�������ú󣬵�û�пɶ�ȡ������ʱ��read������������0��*/
	    {
		buff[nread]='\0';
		char *p;
		int n,num=0;

		if((p=strstr(buff,"$GPRMC"))!=NULL)
//char * strstr��char *1,char *s2��,����s1�е�һ�γ����Ӵ�s2λ�õ�ָ��
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
/*�����Ǻ� (*) ��ʾ���������ݲ�����. (Ҳ���ǲ��Ѵ����ݶ���p��)
%[^a] ƥ���a�������ַ�������ֹͣ����
%*[width] [{h | l | I64 | L}]type ��ʾ����������ı����˵���������Ŀ�������д��ֵ*/
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
