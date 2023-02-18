CC=g++
CFLAGS=-c
all: main.o
	$(CC) main.o -o main.exe -lm
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	rm *o
