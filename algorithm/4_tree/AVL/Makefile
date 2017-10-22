SRC = ${wildcard *.c}
PRGS = ${filter-out queue travel, ${patsubst %.c, %, $(SRC)}}

CC = gcc
CFLAGS = -O0 -g -Wall

all:$(PRGS)

$(PRGS):%:%.c
	$(CC) -o $@ $(CFLAGS) $^ -lvtree -lvqueue

clean:
	- $(RM) -rf .*.swp *.o $(PRGS) *.html

.PHONY:clean
