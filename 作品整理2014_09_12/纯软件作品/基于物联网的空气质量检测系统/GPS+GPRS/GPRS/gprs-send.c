#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>
 
#ifndef  __TTY_H__
#define __TTY_H__

int tty_init();
int tty_end();
int tty_write(char *buf,int nbytes);
int tty_writecmd(char *buf,int nbytes);
int tty_read(char *buf,int nbytes);
#endif

#ifndef __GPRS_H__
#define __GPRS_H__


void gprs_init();
void gprs_msg();
void gprs_read();
#endif

#define BAUDRATE B115200
#define COM1 "/dev/ttyUSB0"
static int fd;
static struct termios oldtio,newtio;

#define ENDMINITERM 27 
#define FALSE	0
#define TRUE  	1
volatile int STOP=FALSE;
int GET_GPRS_OK=FALSE;
int baud=115200;

int tty_end()
{
	tcsetattr(fd,TCSANOW,&oldtio);
	close(fd);
}
int tty_read(char *buf,int nbytes)
{
	return read(fd,buf,nbytes);
}

int tty_write(char *buf,int nbytes)
{
	int i;
	for(i=0; i<nbytes; i++)
	{
		write(fd,&buf[i],1);
		usleep(100);		//睡眠100微秒
	}
	return tcdrain(fd);
}

int tty_writecmd(char *buf,int nbytes)
{
	int i;
	for(i=0; i<nbytes; i++)
	{
		write(fd,&buf[i],1);
		usleep(100);
	}
	write(fd,"\r",1);
	sleep(3);				//睡眠3秒
	return tcdrain(fd);		//等待所有输出都被传送
}

int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop)
{
	if(tcgetattr(fd,&oldtio)  !=  0)
	{
		perror("SetupSerial 1");
		return -1;
	}
	bzero( &newtio, sizeof( newtio ) );newtio.c_cflag  |=  CLOCAL | CREAD;
	newtio.c_cflag &= ~CSIZE;
	switch( nBits )
	{
		case 7:
		newtio.c_cflag |= CS7;
		break;
		case 8:
		newtio.c_cflag |= CS8;
		break;
	}
	switch( nEvent )
	{
		case 'O':
		newtio.c_cflag |= PARENB;
		newtio.c_cflag |= PARODD;
		newtio.c_iflag |= (INPCK | ISTRIP);
		break;
		case 'E':
		newtio.c_iflag |= (INPCK | ISTRIP);
		newtio.c_cflag |= PARENB;
		newtio.c_cflag &= ~PARODD;
		break;
		case 'N':
		newtio.c_cflag &= ~PARENB;
		break;
	}
	switch( nSpeed )
	{
		case 2400:
		cfsetispeed(&newtio, B2400);
		cfsetospeed(&newtio, B2400);
		break;
		case 4800:
		cfsetispeed(&newtio, B4800);
		cfsetospeed(&newtio, B4800);
		break;
		//case 9600:
		//cfsetispeed(&newtio, B9600);
		//cfsetospeed(&newtio, B9600);
		case 115200:
		cfsetispeed(&newtio, B115200);
		cfsetospeed(&newtio, B115200);
		break;
		case 460800:
		cfsetispeed(&newtio, B460800);
		cfsetospeed(&newtio, B460800);
		break;
		default:
		cfsetispeed(&newtio, B9600);
		cfsetospeed(&newtio, B9600);
		break;
	}
	if( nStop == 1 )
		newtio.c_cflag &=  ~CSTOPB;
	else if ( nStop == 2 )
		newtio.c_cflag |=  CSTOPB;
	newtio.c_cc[VTIME]  = 0;
	newtio.c_cc[VMIN] = 0;
	tcflush(fd,TCIFLUSH);
	if((tcsetattr(fd,TCSANOW,&newtio))!=0)
	{
		perror("com set error");
		return -1;
	}
	tcflush(fd,TCIFLUSH);//The `tcflush' function is used to clear the input and/or output
	//queues associated with the terminal file FILEDES.
	printf("set done!\n");
	return 0;
}
//void gprs_msg()
void gprs_msg()
{
    printf("1111111111111111111\n");
	char a;
	char ctl[]={26};
	char text[]="Hello!Witech!";
	//tty_write("at", strlen("at"));
	//sleep(3);
	//write(fd,"\r", 1);
	//printf("666666666666\n");
	//sleep(3);
	tty_write("at+cgdcont=1,\"ip\",\"cmnet\"", strlen("at+cgdcont=1,\"ip\",\"cmnet\""));
	printf("444444444444444444444\n");
         sleep(3);
	write(fd,"\r", 1);
	sleep(3);
	tty_write("at%%etcpip=\"\",\"\"", strlen("at%etcpip=\"\",\"\""));
	printf("777\n");
	sleep(3);
	write(fd,"\r", 1);
	sleep(10);
//	tty_write("at%%etcpip?", strlen("at%etcpip?"));
	printf("22222222222222222222222\n");
	sleep(3);
tty_write("AT%%IPOPEN=\"TCP\",\"202.200.112.220\",1822", strlen("AT%IPOPEN=\"TCP\",\"202.200.112.220\",1822"));
        sleep(3);
        write(fd,"\r", 1);
	sleep(10);
	tty_write("at%%iomode=0,1,1", strlen("at%iomode=0,1,1"));
       sleep(3);
        write(fd,"\r", 1);
	sleep(3);
	printf("333333333333333333333\n");
    tty_write("AT%IPSEND=\"123\"", strlen("AT%IPSEND=\"123\""));
        sleep(3);
        write(fd,"\r", 1);
	sleep(3);
//	tty_write(ctl, 1);
	sleep(3);
	printf("sending is end!!\n");
}

int main(void)
{
	fd = open(COM1, O_RDWR ); //| O_NONBLOCK);//
	if(fd<0)
	{
	   	perror(COM1);
	   	exit(-1);
  	}
	
//  tcgetattr(fd,&oldtio); /* save current modem settings */
//	bzero(&newtio, sizeof(newtio));
	set_opt(fd,115200,8,'N',1);
 	void * retval;
//	tty_init();
	printf("wait for sending a message!\n");
	fflush(stdout);
	printf("sending......\n");
    gprs_msg();
    printf("Bye-Bye!\n");
    tty_end();
    exit(0);
}
