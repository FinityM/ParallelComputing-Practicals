# This is my new Makefile

main_hello: main_hello.c child_hello.c child_hello.o functions.h
	gcc main_hello.c child_hello.o -lpthread -o parallelmean 

child_hello.o: child_hello.c
	gcc -c child_hello.c
clean:
	rm -rf *.exe *.o *.h.gch
