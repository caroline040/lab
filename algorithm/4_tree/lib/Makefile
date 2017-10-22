SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

LIB_PATH = /lib
HEADER_PATH = /usr/include

libvtree.a:$(OBJ)
	$(AR) crs $@ $^ tree_map.o
	@$(RM) $(OBJ) $(OBJ_PATH)

$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^ -c

install:
	cp libvtree.a $(LIB_PATH)
	cp head4tree.h $(HEADER_PATH)

clean:
	@$(RM) .*.sw? $(OBJ) lib*
