SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, %.o, $(SRC)}

CFLAGS = -c -Wall
LIBFLAGS = -shared -fPIC

CC = arm-none-linux-gnueabi-gcc

all:$(OBJ)

$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^

install:
	$(CC) $(LIBFLAGS) -o libvnet.so $(OBJ)
	cp libvnet.so /lib -f
	cp head4sock.h /usr/include -f

clean:
	$(RM) $(OBJ) libvnet.so .*.sw?

.PHONY:all clean
