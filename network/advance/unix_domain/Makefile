# Makefile
#

#CROSS_COMPILE = arm-linux-gnu-

CC = $(CROSS_COMPILE)gcc

ifdef CROSS_COMPILE
TARGET = /opt/filesystem
endif

DEBUG = -g -O0 -Wall

CFLAGS += $(DEBUG) -lvnet

PROGS = ${patsubst %.c, %, ${wildcard *.c}} 

all : $(PROGS)

install: $(PROGS)
ifdef CROSS_COMPILE
	mkdir $(TARGET)/root/long_term/networks_unixdomain -p
	cp $(PROGS) $(TARGET)/root/long_term/networks_unixdomain -f
endif
% : %.c
	$(CC)  $< -o $@  $(CFLAGS)

.PHONY: uninstall clean dist

uninstall :
ifdef CROSS_COMPILE
	cd $(TARGET)/root/long_term/networks_unixdomain && rm -f $(PROGS)
endif

clean : uninstall
	- rm -f $(PROGS) core *.gz

dist: clean
	tar czf farsight_networks_unixdomain_demo1.0.tar.gz *.c custom_product sem Makefile
