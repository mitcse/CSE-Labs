#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	 int fromlen,res,sd,fd1,fd2,size,l,t;
	 char buf1[500],buf2[500];
	 struct sockaddr_in s_address;
	 sd=socket(AF_INET,SOCK_STREAM,0);
	 s_address.sin_family=AF_INET;
	 s_address.sin_addr.s_addr=inet_addr("192.168.100.249");
	 s_address.sin_port=9000;
	 fromlen=sizeof(s_address);
	 res=connect(sd,(struct sockaddr*)&s_address,fromlen);
	 fd1=open("hello",O_RDONLY);
	 fd2=open("output",O_CREAT|O_WRONLY,0777);
	 do
	 {
		  size=read(fd1,buf1,500);
		  if(size>0) write(sd,buf1,size);
	 }while(size>0);
	 close(fd1);
	 do
	 {
		  size=read(sd,buf2,500);
		  if(size>0) write(fd2,buf2,size);
	 }while(size>0);
	 close(fd2);
	 close(sd);
	 return 0;
}