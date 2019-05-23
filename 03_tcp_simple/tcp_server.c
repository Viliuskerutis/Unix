#include <stdio.h>
#include <sys/socket.h>
#include <signal.h>

void main(int argc, char *argv[])
{
    int s,s2,optval;
    struct sockaddr_in sin,sin2;
    int sin2len=sizeof(sin2);
    char buffer[1024];
    int i,retcode,count=0,count_len=0;

    signal(SIGPIPE,SIG_IGN);

    if(argc!=2)
    {
	printf("\n\n\r parameters: %s <port>",argv[0]);
	exit(1);
    }


    s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(s==-1)
    {
	printf("\n\n\r error: scoket()");
	exit(1);
    }

    optval=1;
    retcode=setsockopt(s,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(optval));
    if(retcode!=0)
    {
	printf("\n\n\r error: setsockopt");
	exit(1);
    }

    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=INADDR_ANY;
    sin.sin_port=htons(atoi(argv[1]));

    retcode=bind(s,(struct sockaddr*)&sin,sizeof(sin));
    if(retcode!=0)
    {
	perror("error: bind() ");
//	printf("\n\n\r error: bind(): %d ",retcode);
	exit(2);
    }

    retcode=listen(s,5);
    if(retcode!=0)
    {
	printf("\n\n\r error: listen(): %d ",retcode);
	exit(3);
    }



    printf("\n\n\r waiting for clients, TCP port=%d",ntohs(sin.sin_port));
    while(1)
    {
	count++;
	s2=accept(s,(struct sockaddr*)&sin2,&sin2len);
        char bufferr[4];
        char bufferrr[4];
	printf("\n\n\r %d. client from=%s",count,inet_ntoa(sin2.sin_addr));
	retcode=send(s2,(char*)&buffer,strlen(buffer),0);
	while(1)
	{

	    memset(&buffer,0,sizeof(buffer));
	    printf("\n\r");

	    retcode=recv(s2,(char*)&buffer,sizeof(buffer)-1,0);
	    printf("\n\r recv():%d  -->  '%s' ",retcode,buffer);
	    if(retcode<1)
	    {
		printf("\n\r\t Client disconnected ....");
		break;
	    }
            strncpy(bufferr, buffer, 4);
	    buffer[retcode]='\0';

//	    for(i=0; i<strlen(buffer); i++) buffer[i]=toupper(buffer[i]);
	    memset(buffer,0,sizeof(buffer));
            time_t rawtime;
	    struct tm *timeinfo;
	
	    rawtime=time(NULL);
	    timeinfo=localtime(&rawtime);
	    strftime(buffer,sizeof(buffer)-1,"it's %H:%M:%S ", timeinfo );
		sprint(bufferrr,sizeof(bufferrr)-1,"Hello %s, %s",bufferr, buffer);

	    retcode=send(s2,(char*)&bufferrr,strlen(bufferrr),0);
	    printf("\n\r send():%d  -->  '%s' ",retcode,bufferrr);
	    if(retcode<1)
	    {
		printf("\n\r\t Client disconnected ....");
		break;
	    }

	}

        printf("\n\r ----------------------------------------------------------\n\n\r");
	close(s2);
    }


}
