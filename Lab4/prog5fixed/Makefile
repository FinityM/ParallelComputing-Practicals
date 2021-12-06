main: main.c sum_func.c sum_func.o functions.h 
	gcc main.c sum_func.o -lpthread -o prog5

sum_func.o: sum_func.c
	gcc -c sum_func.c

clean:
	rm -rf *.exe *.o *.h.gch *.c~ makefile~ *.h~ 