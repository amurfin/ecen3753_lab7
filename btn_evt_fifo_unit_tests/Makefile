UNAME=$(shell uname)

CCFLAGS=-Wall -O3 -std=gnu99
CC=gcc

all: btnevtfifo

btnevtfifo: main.o btnevtfifo.o ctest.h btnevtfifo_tests.o
	$(CC) $(LDFLAGS) main.o btnevtfifo.o btnevtfifo_tests.o -o btnevtfifo

remake: clean all

%.o: %.c ctest.h
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f btnevtfifo *.o
