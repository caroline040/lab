all:libvsort.so

libvsort.so:sort.c
	$(CC) sort.c -o sort.o -c
	gcc -fPIC -shared -o $@ sort.o

install:
	sudo cp libvsort.so /usr/lib
	sudo cp head4sort.h /usr/include

clean:
	rm libvsort.so *.o -f
disclean:
	sudo rm libvsort.so /usr/lib/libvsort.so *.o -f
