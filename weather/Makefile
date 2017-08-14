vpath %.c = src/
vpath %.h = inc/

SRC += $(wildcard *.c)

#CROSS = arm-none-linux-gnueabi-
CC = $(CROSS)gcc

CPPFLAGS += -I cJSON/

LDFLAGS += -L cJSON/
LDFLAGS += -lcjson
LDFLAGS += -Wl,-rpath=./cJSON


weather.out:$(SRC)
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS) -DNDEBUG

debug.out:$(SRC)
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS) -DDEBUG

clean:
	$(RM) *.out

distclean:clean
	$(RM) core .*.sw? *.html
