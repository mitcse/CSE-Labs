#include <sys/un.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
        char buf1[500], buf2[500];
        struct sockaddr_in s_address, c_address;
        int a,fd1,fd2,sd,ns,ns2,rsize,wsize,t;
        int fromlen;
        sd=socket(AF_INET,SOCK_STREAM,0);
        s_address.sin_family=AF_INET;
        s_address.sin_addr.s_addr=inet_addr("192.168.100.203");
        s_address.sin_port=9000;
        a = bind(sd, (struct sockaddr*)&s_address, sizeof(s_address));
        listen(sd,1);
        fd1=open("objcode",O_CREAT|O_RDWR,0777);
        for(;;)
        {
                ns=accept(sd, (struct sockaddr*)&c_address, &fromlen);
                close(sd);
                do
                {
			 t=read(ns,buf1,500);
			 if(t>0) write(fd1,buf1,t);
                }while(t>0);
                close(fd1);
                system("chmod 777 objcode");
                system("./objcode>op");
	        fd2=open("op",O_RDONLY);
		do
		{
			t=read(fd2,buf1,500);
			if(t>0) write(ns,buf1,t);
		}while(t>0);
		close(fd2);    
		return(0);
	}
 	close(ns);
   	return 0;
}