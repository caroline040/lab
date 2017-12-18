///////////////////////////////////////////////////////////
//
//  Copyright(C), 2013-2017, GEC Tech. Co., Ltd.
//
//  文件: lab/uart/example2.c
//
//  日期: 2017-12
//  描述: 两个串口之间发送数据（带帧检测）
//
//  作者: Vincent Lin (林世霖)  
//  微信公众号：秘籍酷
//
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <fcntl.h>
#include <termios.h>
#include <pthread.h>

#include <dirent.h>

#define BUFSIZE 1024

void init_tty(int fd)
{
	struct termios new_cfg, old_cfg;
	if(tcgetattr(fd, &old_cfg) != 0)
	{
		perror("tcgetattr() failed");
		exit(0);
	}

	bzero(&new_cfg, sizeof(new_cfg));

	new_cfg = old_cfg;
	cfmakeraw(&new_cfg);

	cfsetispeed(&new_cfg, B115200);
	cfsetospeed(&new_cfg, B115200);

	new_cfg.c_cflag |= CLOCAL | CREAD;

	new_cfg.c_cflag &= ~CSIZE;
	new_cfg.c_cflag |= CS8;

	new_cfg.c_cflag &= ~PARENB;
	new_cfg.c_cflag &= ~CSTOPB;

	new_cfg.c_cc[VTIME] = 0;
	new_cfg.c_cc[VMIN]  = 1;
	tcflush(fd, TCIFLUSH);

	if(tcsetattr(fd, TCSANOW, &new_cfg) != 0)
	{
		perror("tcsetattr() failed");
		exit(0);
	}
}

void *routine(void *arg)
{
	int fd_recv = *(int *)arg;

	char *buf= calloc(1, BUFSIZE);

	int n;
	while(1)
	{
		bzero(buf, BUFSIZE);

		n = read(fd_recv, buf, BUFSIZE);
		if(n > 0)
		{
			fprintf(stderr, "recv: %s", buf);
		}
	}

}

char *menu(void)
{
	printf("1: /dev/ttySAC1\n");
	printf("2: /dev/ttySAC2\n");
	printf("3: /dev/ttySAC3\n");
	printf("4: /dev/ttySAC4\n");

	int n;
	scanf("%d", &n);

	switch(n)
	{
	case 1: return "/dev/ttySAC1";	
	case 2: return "/dev/ttySAC2";	
	case 3: return "/dev/ttySAC3";	
	case 4: return "/dev/ttySAC4";	
	}

	return NULL;
}

int main(void)
{
	// GEC6818默认串口名称：/dev/ttySACx
	char *tty_send;
	char *tty_recv;

	printf("请选择发送端串口:\n");
	tty_send = menu();
	printf("请选择接收端串口:\n");
	tty_recv = menu();

	// 打开指定的串口设备节点，并初始化
	int fd_send = open(tty_send, O_RDWR|O_NOCTTY);
	if(fd_send == -1)
	{
		fprintf(stderr, "open() %s failed: %s\n",
				tty_send, strerror(errno));
		exit(0);
	}

	int fd_recv = open(tty_recv, O_RDWR|O_NOCTTY);
	if(fd_recv == -1)
	{
		fprintf(stderr, "open() %s failed: %s\n",
				tty_recv, strerror(errno));
		exit(0);
	}
	init_tty(fd_send);
	init_tty(fd_recv);

	// ============ 独立线程读取串口信息 ============== //
	pthread_t tid;
	pthread_create(&tid, NULL, routine, (void *)&fd_recv);


	// ============ 主线程发送串口信息 ============ //
	char *buf = calloc(1, BUFSIZE);
	while(1)
	{
		bzero(buf, BUFSIZE);
		fgets(buf, BUFSIZE, stdin);

		write(fd_send, buf, strlen(buf));
	}

	return 0;
}
