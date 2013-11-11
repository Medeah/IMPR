CC = gcc

all: ppm.o pixel.o prog.c
	$(CC) -Wall -g -lm prog.c pixel.o ppm.o -o prog

prog: ppm.o pixel.o prog.c
	$(CC) -Wall -g -lm prog.c pixel.o ppm.o -o prog

ppm.o: ppm.h ppm.c
	$(CC) -c ppm.c

pixel.o: pixel.c pixel.c
	$(CC) -c pixel.c

clean:
	rm prog img1.pnm *o