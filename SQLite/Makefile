CPPFLAGS += -I inc/

LDFLAGS += -L lib/
LDFLAGS += -lsqlite3
LDFLAGS += -lpthread
LDFLAGS += -ldl
LDFLAGS += -Wl,-rpath=./lib 

demo:demo.c wrap.c lib/libsqlite3.so
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS)

lib/libsqlite3.so:
	$(MAKE) -C lib

clean:
	$(RM) demo
