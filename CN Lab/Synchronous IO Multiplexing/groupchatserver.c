     #include <stdio.h>

    #include <stdlib.h>

    #include <string.h>

    #include <unistd.h>

    #include <sys/types.h>

    #include <sys/socket.h>

    #include <netinet/in.h>

    #include <arpa/inet.h>

    /* port we're listening on */

    #define PORT 19999

    #define SERVER "172.16.59.20"

     

    int main(int argc, char *argv[])

    {

        

        fd_set master;
        fd_set read_fds;
        struct sockaddr_in serveraddr;
        struct sockaddr_in clientaddr;
        int fdmax;
        int listener;
        int newfd;
        char buf[5000];
        int nbytes;
        int yes = 1;
        int addrlen;
        int i, j;
        FD_ZERO(&master);
        FD_ZERO(&read_fds);
      


         

        

        if((listener = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        {

        perror("Server-socket() error ");
        exit(1);

        }

        printf("Server-socket() is OK...\n");

        

        if(setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)

        {

            perror("Server-setsockopt() error");

            exit(1);

        }

        printf("Server-setsockopt() is OK...\n");

         


        serveraddr.sin_family = AF_INET;

        serveraddr.sin_addr.s_addr = inet_addr(SERVER);

        serveraddr.sin_port = htons(PORT);

        memset(&(serveraddr.sin_zero), '\0', 8);

         

        if(bind(listener, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1)

        {

            perror("Server-bind() error ");

            exit(1);

        }

        printf("Server-bind() is OK...\n");

         


        if(listen(listener, 1000) == -1)

        {

             perror("Server-listen() error ");

             exit(1);

        }

        printf("Server-listen() is OK...\n");

         

       

        FD_SET(listener, &master);

        

        fdmax = listener; 

         

        

        for(;;)

        {

        

            read_fds = master;

             

            if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1)

            {

                perror("Server-select() error lol!");

                exit(1);

            }

            printf("Server-select() is OK...\n");

            for(i = 0; i <= fdmax; i++)

            {

                if(FD_ISSET(i, &read_fds))

                { 
                    if(i == listener)
                    {

                     

                        addrlen = sizeof(clientaddr);
                        if((newfd = accept(listener, (struct sockaddr *)&clientaddr, &addrlen)) == -1)

                        {

                            perror("Server-accept() error");

                        }

                        else

                        {

                            printf("Server-accept() is OK...\n");
                            FD_SET(newfd, &master); 
                            if(newfd > fdmax)
                            { 

                                fdmax = newfd;

                            }

                            printf("%s: New connection from %s on socket %d\n", argv[0], inet_ntoa(clientaddr.sin_addr), newfd);

                        }

                    }

                    else

                        {

                            if((nbytes = recv(i, buf, sizeof(buf), 0)) <= 0)
                            {
                                if(nbytes == 0)

                            

                                printf("%s: socket %d hung up\n", argv[0], i);

                             

                                else

                                perror("recv() error");

                             

                            

                                close(i);

                            

                                FD_CLR(i, &master);

                            }

                            else

                            {

                            

                                for(j = 0; j <= fdmax; j++)

                                {

                            

                                    if(FD_ISSET(j, &master))

                                    {

                                   

                                        if(j != listener && j != i)

                                        {

                                            if(send(j, buf, nbytes, 0) == -1)

                                                 perror("send() error");

                                        }

                                    }

                                }

                            }

                        }

                }

            }

        }

    return 0;

}
