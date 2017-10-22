CC = arm-none-linux-gnueabi-gcc

BIN = example1.elf example2.elf 

all:$(BIN)

$(BIN):%.elf:%.c
	$(CC) $^ -o $@ -lpthread

clean:
	$(RM) $(BIN)
