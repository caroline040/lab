CPPFLAGS += -I inc/

LDFLAGS += -L lib/
LDFLAGS += -lsqlite3
LDFLAGS += -lpthread
LDFLAGS += -ldl
LDFLAGS += -Wl,-rpath=./lib 

demo:demo.c wrap.c
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS)

clean:
	$(RM) demo
