CC = gcc
CFLAGS = -O0 -Wall -g -lpthread

test.out:main.c thread_pool.c
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	$(RM) .*.sw? test.out *.o

.PHONY:all clean
