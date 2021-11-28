# This is my new Makefile

main_hello: main_hello.c child_hello.c child_hello.o
	gcc main_hello.c child_hello.o -lpthread -o prog3

child_hello.o: child_hello.c
	gcc -c child_hello.c

