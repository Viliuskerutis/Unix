#include <stdio.h>
#include <sys/socket.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

void main(int argc, char *argv[])
{
    int s,i,retcode,len;
    struct sockaddr_in sin;
    char buffer[1024];

    signal(SIGPIPE,SIG_IGN);

    if(argc!=3)
    {
	printf("\n\r Parameters: %s <host> <port> ",argv[0]);
	exit(1);
    }

    s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(s==-1)
    {
	perror("error: socket(): ");
	exit(1);
    }

    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=inet_addr(argv[1]);
    sin.sin_port=htons(atoi(argv[2]));

    printf("\n\n\r");
    retcode=connect(s,(struct sockaddr *)&sin,sizeof(sin)); 
    if(retcode!=0)
    {
	perror("error: connect(): ");
	exit(1);
    }

    while(1)
    {
        memset(&buffer,0,sizeof(buffer));
	printf("\n\r");
	
	strcpy(buffer,"some data to process");

	retcode=send(s,(char*)&buffer,strlen(buffer),0);
	printf("\n\r send(): '%s' [%d] ", buffer, retcode);
	if(retcode<1) break;

        memset(&buffer,0,sizeof(buffer));
	retcode=recv(s,(char*)buffer,sizeof(buffer)-1,0);
	buffer[retcode]=0;
	printf("\n\r recv(): '%s' [%d] ", buffer, retcode);
	if(retcode<1) break;

	sleep(4);
    }
    
    close(s);
    printf("\n\n\r Client disconnected ...\n\n\r");
    
}

