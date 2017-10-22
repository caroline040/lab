PRGS = ${patsubst %.c, %, ${wildcard *.c}}
DEBUG := -O0 -g -Wall
CFLAGS += $(DEBUG)

all:fifo_server fifo_client

fifo_server:restart.c fifo_server.c
	$(CC) $(CFLAGS) -o $@ restart.c fifo_server.c

fifo_client:restart.c fifo_client.c
	$(CC) $(CFLAGS) -o $@ restart.c fifo_client.c

clean:
	$(RM) -rf .*.sw? *.o $(PRGS) p
.PHONY:clean
