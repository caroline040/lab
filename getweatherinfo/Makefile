vpath %.c = src/
vpath %.h = inc/

SRC += $(wildcard *.c)

#CROSS = arm-none-linux-gnueabi-
CC = $(CROSS)gcc

CPPFLAGS += -I inc/
CPPFLAGS += -I inc/cjson/

LDFLAGS += -L lib/
LDFLAGS += -lcjson


getweatherinfo:$(SRC)
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS) -DNDEBUG

debug:$(SRC)
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS) -DDEBUG

clean:
	$(RM) getweatherinfo debug

distclean:clean
	$(RM) core .*.sw? *.html
