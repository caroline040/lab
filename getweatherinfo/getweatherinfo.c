#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <strings.h>

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
const char month_tab[48] =
"Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec ";
const char day_tab[] = "Sun,Mon,Tue,Wed,Thu,Fri,Sat,";



#define MSG "GET /phone-post-code-weeather?"\
	"need3HourForcast=0&"\
	"needAlarm=0&"\
	"needHourData=0&"\
	"needIndex=0&"\
	"needMoreDay=0&"\
	"phone_code=0755&"\
	"post_code=0 "\
	"HTTP/1.1\r\n"\
	"Content-Length:129\r\n"\
	"User-Agent:Mozilla/5.0(Macintoh;Intel Mac OS X 1_12_0) "\
	"AppleWebKit/537.36(KHTML,like Gecko) Chrome/56.0.2924.87 Safari/537.36\r\n\r\n"

struct in_addr **addr;
void rfc822_time_buf(char *buf, time_t s)
{
    struct tm *t;
    char *p;
    unsigned int a;
    time_t current_time;
    time(&current_time);
    if (!s) {
        t = gmtime(&current_time);
    } else
        t = gmtime(&s);

    p = buf + 28;
    /* p points to the last char in the buf */

    p -= 3;
    /* p points to where the ' ' will go */
    memcpy(p--, " GMT", 4);

    a = t->tm_sec;
    *p-- = '0' + a % 10;
    *p-- = '0' + a / 10;
    *p-- = ':';
    a = t->tm_min;
    *p-- = '0' + a % 10;
    *p-- = '0' + a / 10;
    *p-- = ':';
    a = t->tm_hour;
    *p-- = '0' + a % 10;
    *p-- = '0' + a / 10;
    *p-- = ' ';
    a = 1900 + t->tm_year;
    while (a) {
        *p-- = '0' + a % 10;
        a /= 10;
    }
    /* p points to an unused spot to where the space will go */
    p -= 3;
    /* p points to where the first char of the month will go */
    memcpy(p--, month_tab + 4 * (t->tm_mon), 4);
    *p-- = ' ';
    a = t->tm_mday;
    *p-- = '0' + a % 10;
    *p-- = '0' + a / 10;
    *p-- = ' ';
    p -= 3;
    memcpy(p, day_tab + t->tm_wday * 4, 4);
}
void remote_info(struct hostent *he)
{
    assert(he);

    printf("主机的官方名称：%s\n", he->h_name);

    int i;
    for(i=0; he->h_aliases[i]!=NULL; i++)
    {
        printf("别名[%d]：%s\n", i+1, he->h_aliases[i]);
    }

    printf("IP地址长度：%d\n", he->h_length);


	addr = (struct in_addr **)he->h_addr_list;
	for(i=0; he->h_addr_list[i]!=NULL; i++)
	{
		printf("IP地址[%d]：%s\n", i+1, inet_ntoa(*addr[i]));
	}
}
void makeMsg(char*buf)
{
    char tmp[1000];
    if(buf==NULL)
        return;
    char *p=buf;
    memset(tmp,0,sizeof(tmp));
    sprintf(tmp,"GET /phone-post-code-weeather?"\
	"need3HourForcast=0&"\
	"needAlarm=0&"\
	"needHourData=0&"\
	"needIndex=0&"\
	"needMoreDay=0&"\
	"phone_code=0755&"\
	"post_code=0 "\
	"HTTP/1.1\r\n");
    memcpy(p,tmp,strlen(tmp));
    p+=strlen(tmp);
    memset(tmp,0,sizeof(tmp));
    sprintf(tmp,"Content-Length:0\r\n"\
	"User-Agent:Mozilla/5.0(Macintoh;Intel Mac OS X 1_12_0) "\
	"AppleWebKit/537.36(KHTML,like Gecko) Chrome/56.0.2924.87 Safari/537.36\r\n");
    memcpy(p,tmp,strlen(tmp));
    p+=strlen(tmp);
    char stuff[] = "Date: "
        "                             "
        "\r\n";
    memset(tmp,0,sizeof(tmp));
    sprintf(p,"Date: ");
    p+=strlen("Date: ");
    rfc822_time_buf(tmp, 0);
    memcpy(p,tmp,strlen(tmp));
    p+=strlen(tmp);
    memset(tmp,0,sizeof(tmp));
    sprintf(tmp,"\r\nServer: cagaccesstengine010151203185.cm9\r\n");
   memcpy(p,tmp,strlen(tmp));
    p+=strlen(tmp);
    memset(tmp,0,sizeof(tmp));
    sprintf(tmp,"Content-Type:application/json; charset=utf-8\r\n");
    memcpy(p,tmp,strlen(tmp));
    p+=strlen(tmp);
    memset(tmp,0,sizeof(tmp));
    sprintf(tmp,"Host:ali-weather.showapi.com\r\nAccept:application/json\r\n");
    memcpy(p,tmp,strlen(tmp));
    p+=strlen(tmp);
    memset(tmp,0,sizeof(tmp));
    sprintf(tmp,"Authorization:APPCODE d487d937315848af80710a06f4592fee\r\n");
    memcpy(p,tmp,strlen(tmp));
    p+=strlen(tmp);
    memcpy(p,"\r\n",2);
    memcpy(p,"\r\n",2);


}


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: %s <domain-name>\n", argv[0]);	
		exit(0);
	}
	struct hostent *he = gethostbyname(argv[1]);

	// 查看服务端信息，且顺便获取IP地址
	remote_info(he);

	int fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in srvaddr;
	socklen_t len = sizeof(srvaddr);
	bzero(&srvaddr, len);

	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port   = htons(80);
	srvaddr.sin_addr   = *addr[0];

	if(connect(fd, (struct sockaddr *)&srvaddr, len) == -1)
	{
		perror("connect() failed");
		exit(0);
	}
	printf("connect successful!\n");

	int n;
    char buf[1000];
    memset(buf,0,1000);
    makeMsg(buf);   
    printf("%s\n",buf);
	n = send(fd, buf, strlen(buf), 0);
	if(n == -1)
	{
		perror("send() failed");
		exit(0);
	}
	printf("[%d] bytes have been sent.\n", n);

	char *recvbuf = calloc(1, 2000);
	n = recv(fd, recvbuf, 2000, 0);
	if(n == -1)
	{
		perror("recv() failed");
		exit(0);
	}
	printf("[%d] bytes have been received.\n", n);

	printf("\n返回结果: \n*******************************\n");
	printf("%s", recvbuf);
	printf("*******************************\n\n");

#ifdef DEBUG
	FILE *fp = fopen("a.html", "w");
	fwrite(recvbuf, strlen(recvbuf), 1, fp);
	fclose(fp);

	system("firefox a.html");
#endif
	return 0;
}
