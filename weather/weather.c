//////////////////////////////////////////////////////////////////
//
//  Copyright(C), 2013-2016, GEC Tech. Co., Ltd.
//
//  File name: lab/getweatherinfo/getweatherinfo.c
//
//  Author: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  Date: 2017-8
//  
//  Description: get city weather info by phone-code
//
//  GitHub: github.com/vincent040   Bug Report: 2437231462@qq.com
//
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <strings.h>

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "cJSON.h"

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

	for(i=0; he->h_addr_list[i]!=NULL; i++)
	{
		printf("IP地址[%d]：%s\n", i+1,
			inet_ntoa(*((struct in_addr **)he->h_addr_list)[i]));
	}
}


void http_request(char*buf, int size, char *phone_code)
{
	assert(buf);
	assert(phone_code);

	bzero(buf, size);
	snprintf(buf, size, "GET /phone-post-code-weeather?"
			    "phone_code=%s "
			    "HTTP/1.1\r\n"
			    "Host:ali-weather.showapi.com\r\n"
			    "Authorization:APPCODE d487d937315848af80710a06f4592fee\r\n\r\n",
			    phone_code);
}

void show_weather_info(char *json)
{
	cJSON *root     = cJSON_Parse(json);

	cJSON *body     = cJSON_GetObjectItem(root, "showapi_res_body");
	cJSON *now      = cJSON_GetObjectItem(body, "now");
	cJSON *cityInfo = cJSON_GetObjectItem(body, "cityInfo");
	cJSON *today    = cJSON_GetObjectItem(body, "f1");
	cJSON *tomorrow = cJSON_GetObjectItem(body, "f2");
	cJSON *day_3rd  = cJSON_GetObjectItem(body, "f3");


	char *country = cJSON_GetObjectItem(cityInfo, "c9")->valuestring;
	char *province= cJSON_GetObjectItem(cityInfo, "c7")->valuestring;
	char *city    = cJSON_GetObjectItem(cityInfo, "c5")->valuestring;

	bool zhixiashi = !strcmp(city, province);
	printf("城市：%s·%s%s%s\n\n", country, province, zhixiashi ? "" : "·", zhixiashi ? "" : city);

	printf("现在天气：%s\n",    cJSON_GetObjectItem(now, "weather")->valuestring);
	printf("现在气温：%s°C\n\n",cJSON_GetObjectItem(now, "temperature")->valuestring);

	printf("明天天气：%s\n",     cJSON_GetObjectItem(tomorrow, "day_weather")->valuestring);
	printf("日间气温：%s°C\n",   cJSON_GetObjectItem(tomorrow, "day_air_temperature")->valuestring);
	printf("夜间气温：%s°C\n\n", cJSON_GetObjectItem(tomorrow, "night_air_temperature")->valuestring);

	printf("后天天气：%s\n",     cJSON_GetObjectItem(day_3rd, "day_weather")->valuestring);
	printf("日间气温：%s°C\n",   cJSON_GetObjectItem(day_3rd, "day_air_temperature")->valuestring);
	printf("夜间气温：%s°C\n\n", cJSON_GetObjectItem(day_3rd, "night_air_temperature")->valuestring);
}


int main(int argc, char **argv)
{
	printf("input phone code: \n");

	char phone_code[5];
	bzero(phone_code, 5);
	scanf("%s", phone_code);

	char *host = "ali-weather.showapi.com";
	struct hostent *he = gethostbyname(host);

#ifdef DEBUG
	remote_info(he);
#endif

	struct in_addr **addr_list = (struct in_addr **)(he->h_addr_list);

	int fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in srvaddr;
	socklen_t len = sizeof(srvaddr);
	bzero(&srvaddr, len);

	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port   = htons(80);
	srvaddr.sin_addr   = *addr_list[0];

	if(connect(fd, (struct sockaddr *)&srvaddr, len) == -1)
	{
		perror("connect() failed");
		exit(0);
	}

	char *sndbuf = calloc(1, 1000);
	http_request(sndbuf, 1000, phone_code);   

#ifdef DEBUG
	printf("Request:\n");
	printf("+++++++++++++++++++++++++++++++\n");
	printf("%s", sndbuf);
	printf("+++++++++++++++++++++++++++++++\n\n");
#endif

	int n = send(fd, sndbuf, strlen(sndbuf), 0);
	if(n == -1)
	{
		perror("send() failed");
		exit(0);
	}

#ifdef DEBUG
	printf("[%d] bytes have been sent.\n", n);
#endif

	free(sndbuf);

	char *recvbuf = calloc(1, 4096);
	int m = 0;

#ifdef DEBUG
	printf("Response:\n");
	printf("*******************************\n");
#endif

	while(1)
	{
		n = recv(fd, recvbuf+m, 2000, 0);
		if(n == 0)
			break;
		if(n == -1)
		{
			perror("recv() failed");
			exit(0);
		}
#ifdef DEBUG
		printf("%s\n", recvbuf+m);
#endif

		m += n;

		if(strstr(recvbuf, "}}") || strstr(recvbuf, "400 Bad Request"))
			break;

		if(strstr(recvbuf, "Quota Exhausted"))
		{
			printf("API查询次数已超，请续费。\n");
			exit(0);
		}
	}

#ifdef DEBUG
	printf("*******************************\n");
	printf("[%d] bytes have been received.\n\n", m);
#endif

	show_weather_info(strstr(recvbuf, "{"));
	free(recvbuf);

	return 0;
}
