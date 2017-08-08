CC = gcc
CFLAGS = -O0 -Wall -g -lpthread

copy:copy.c thread_pool.c
	$(CC) $^ -o $@ $(CFLAGS) -DNDEBUG

debug:copy.c thread_pool.c
	$(CC) $^ -o $@ $(CFLAGS) -DDEBUG

clean:
	$(RM) .*.sw? copy debug *.o bk -rf

.PHONY:all clean
