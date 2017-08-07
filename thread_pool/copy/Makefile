CC = gcc
CFLAGS = -O0 -Wall -g -lpthread

debug:copy.c thread_pool.c
	$(CC) $^ -o $@ $(CFLAGS) -DDEBUG

copy:copy.c thread_pool.c
	$(CC) $^ -o $@ $(CFLAGS) -DNDEBUG

clean:
	$(RM) .*.sw? copy debug *.o

.PHONY:all clean
