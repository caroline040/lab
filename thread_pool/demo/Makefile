CC = gcc
CFLAGS = -O0 -Wall -g -lpthread

test:main.c thread_pool.c
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	$(RM) .*.sw? test *.o

.PHONY:all clean
