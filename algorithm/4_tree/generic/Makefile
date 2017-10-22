SRC = $(wildcard *.c)
BIN = $(patsubst %.c, %, $(SRC))

CC = gcc
CFLAGS = -O0 -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^ -lvqueue -lvstack -lvtree

clean:
	@$(RM) -rf .*.swp *.o $(BIN)

.PHONY:clean
