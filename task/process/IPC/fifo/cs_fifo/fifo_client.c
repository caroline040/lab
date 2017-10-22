#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "restart.h"

#define FIFO_ARG 1

int main(int argc, char **argv)
{
	if(argc != 2){
		fprintf(stderr, "Command error! Usage: %s"
			" <FIFO name>\n", argv[0]);
		return -1;
	}

	/* open the FIFO */
	int fd;
	if((fd=r_open2(argv[FIFO_ARG], O_WRONLY)) == -1){
		perror("open failed");
		return -1;
	}

	pid_t pid;
	int i;
	/* create a process fan */
	for(i=0; i<100; i++){
		sleep(1);
		if((pid=fork()) == 0)
			break;
		else if(pid < 0){
			perror("fork failed");
			break;
		}
	}

	char buf[PIPE_BUF];
	time_t t_loc;
	time(&t_loc);
	int len;

	snprintf(buf, PIPE_BUF, "[PID: %ld]: %s",
			(long)getpid(), ctime(&t_loc));
	len = strlen(buf);
	if(r_write(fd, buf, strlen(buf)) != len){
		perror("Client falied to write");
		return 1;
	}

	close(fd);
	return 0;
}
