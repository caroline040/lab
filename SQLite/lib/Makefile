
libsqlite3.so:sqlite3.o
	$(CC) -fPIC -shared -o $@ $^
	$(RM) $^

sqlite3.o:sqlite3.c
	$(CC) -fPIC -o $@ $^ -c

clean:
	$(RM) *.o *.so
