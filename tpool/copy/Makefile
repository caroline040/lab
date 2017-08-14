CC = gcc
CFLAGS = -O0 -Wall -g -lpthread

copy.out:copy.c thread_pool.c
	$(CC) $^ -o $@ $(CFLAGS) -DNDEBUG

debug.out:copy.c thread_pool.c
	$(CC) $^ -o $@ $(CFLAGS) -DDEBUG

clean:
	$(RM) .*.sw? copy.out debug.out *.o bk -rf

.PHONY:all clean
