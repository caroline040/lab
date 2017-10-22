#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "restart.h"

#define FIFO_ARG 1
#define FIFO_PERMS (S_IRWXU | S_IRGRP | S_IROTH)

int main(int argc, char **argv)
{
	int fd;

	if(argc != 2){
		fprintf(stderr, "Command error! Usage:  <FIFO name>\n");
		return -1;
	}

	/* create a FIFO */
	if(((mkfifo(argv[FIFO_ARG], FIFO_PERMS)) == -1) && (errno != EEXIST)){
		perror("mkfifo failed");
		return -1;
	}

	/* open the FIFO for read & write */
	if((fd=r_open2(argv[FIFO_ARG], O_RDONLY)) == -1){
		perror("open failed");
		return -1;
	}

	/* read the FIFO and output to the stdout */
	printf("%d\n", transmit(fd, STDOUT_FILENO));
	return 0;
}
