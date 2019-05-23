#include <stdio.h>
#include <sys/socket.h>
#include <string.h>

int main(int argc, char**argv)
{
    int s,retcode,count=0;
    struct sockaddr_in sin_server,sin_client;
    int i,len,sin_client_len;
    char buffer[256];

    if(argc!=2)
    {
	printf("\n\r Enter port: %s <port>",argv[0]);
	exit(1);
    }

    s=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    printf("\n\r socket(): %d",s);

    memset(&sin_server,0,sizeof(sin_server));
    sin_server.sin_family = AF_INET;
    sin_server.sin_addr.s_addr=INADDR_ANY;
    sin_server.sin_port=htons(atoi(argv[1]));
    
    retcode=bind(s,(struct sockaddr *)&sin_server,sizeof(sin_server));
    printf("\n\r bind(): %d ",retcode);
    printf("\n\r waiting for clients, port=%d.... ",ntohs(sin_server.sin_port));


    while(1)
    {
	memset(buffer,0,sizeof(buffer));
	sin_client_len = sizeof(sin_client);
	len = recvfrom(s,buffer,sizeof(buffer)-1,0,(struct sockaddr *)&sin_client,&sin_client_len);
        char bufferr[4];
        strncpy(bufferr, buffer, 4 );
	buffer[len]=0;
	printf("\n\n\r %d. Client: IP: %s [%d]  ",count++,inet_ntoa(sin_client.sin_addr),ntohs(sin_client.sin_port));
	printf("\n\r\t recvfrom():  '%s' [%d] ",buffer,len);

	// 2nd variant sending string with date and time
	memset(&buffer,0,sizeof(buffer));
	time_t rawtime;
	struct tm *timeinfo;
	printf("Kazkas: %s", bufferr);
	rawtime=time(NULL);
	timeinfo=localtime(&rawtime);
	if (!strcmp(bufferr, "time")){
        strftime(buffer,sizeof(buffer)-1,"Time: %H:%M:%S ",timeinfo);
	}
        if (!strcmp(bufferr, "date")){
        strftime(buffer,sizeof(buffer)-1,"Date: %d.%m.%Y ",timeinfo);
        }
	len=sendto(s,buffer,strlen(buffer),0,(struct sockaddr *)&sin_client,sizeof(sin_client));
	printf("\n\r\t sendto(): '%s'  [%d] ",buffer,len);
	
   }
   
   
}
