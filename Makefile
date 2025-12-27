CFLAGS = -Wall -Wextra -std=c99
all: parser_example

parser_example: main.o parser.o
	gcc  $(CFLAGS) -o parser_example main.o parser.o

main.o: main.c parser.h
	gcc $(CFLAGS) -c main.c -o main.o

parser.o: parser.c parser.h
	gcc $(CFLAGS) -c parser.c -o parser.o

clean:
	rm -f *.o parser_example
