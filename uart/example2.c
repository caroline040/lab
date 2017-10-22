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
	int fd = *(int *)arg;

	char *buf= calloc(1, BUFSIZE);
	int n;
	while(1)
	{
		bzero(buf, BUFSIZE);

		n = read(fd, buf, BUFSIZE);
		if(n > 0)
		{
			fprintf(stderr, "%s", buf);
		}
	}

}

int main(void)
{
	// GEC6818默认串口名称：/dev/ttySACx
	char *tty = "/dev/ttySAC1";

	// 打开指定的串口设备节点，并初始化
	int fd = open(tty, O_RDWR|O_NOCTTY);
	if(fd == -1)
	{
		fprintf(stderr, "open() %s failed: %s\n",
				tty, strerror(errno));
		exit(0);
	}
	init_tty(fd);

	// ============ 独立线程读取串口信息 ============== //
	pthread_t tid;
	pthread_create(&tid, NULL, routine, (void *)&fd);


	// ============ 主线程发送串口信息 ============ //
	char *buf = calloc(1, BUFSIZE);
	while(1)
	{
		bzero(buf, BUFSIZE);
		fgets(buf, BUFSIZE, stdin);

		write(fd, buf, strlen(buf));
	}

	return 0;
}
