all: main.o
	gcc main.o -o main.exe -lm
main.o: main.c stb_image.h
	gcc -c main.c
clean:
	rm *o
