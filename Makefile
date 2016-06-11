CC = gcc
CFLAGS = -Wall -Wextra -g -O0

all: tp1.exe

tp1.exe: tp1.o function_tp1.o
	$(CC) $(CFLAGS) tp1.o function_tp1.o -lm -o tp1.exe

tp1.o: tp1.c arvoreb+.h
	$(CC) $(CFLAGS) -c tp1.c

function_tp1.o: function_tp1.c arvoreb+.h
	$(CC) $(CFLAGS) -c function_tp1.c

clean:
	rm *.o tp1.exe
