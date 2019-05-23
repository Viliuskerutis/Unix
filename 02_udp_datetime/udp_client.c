#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char**argv)
{
    int s,len;
    struct sockaddr_in sin_server;
    char buffer[1000];


    if (argc != 3)
    {
	printf("Enter: %s <IP address> <port> \n",argv[0]);
	exit(1);
    }

    s=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    printf("\n\r socket(): ",s);

    memset(&sin_server,0,sizeof(sin_server));
    sin_server.sin_family = AF_INET;
    sin_server.sin_addr.s_addr=inet_addr(argv[1]);
    sin_server.sin_port=htons(atoi(argv[2]));


    while(1)
    {
	printf("\n\n\r");

	sprintf(buffer,"datetime");
	len=sendto(s,buffer,strlen(buffer),0, (struct sockaddr *)&sin_server,sizeof(sin_server));
	printf("\n\r sendto(): '%s' [%d]",buffer,len);

        len=recvfrom(s,buffer,sizeof(buffer),0,NULL,NULL);
        buffer[len]=0;
	printf("\n\r recvfrom(): '%s' [%d]",buffer,len);
	
	_sleep(1);
   }
   
   
}
