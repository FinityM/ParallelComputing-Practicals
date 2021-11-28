main: main.c sum_func.c mean_func.c sum_func.o mean_func.o libVarsFunc.h
	gcc main.c sum_func.o mean_func.o -lpthread -o prog5

sum_func.o: sum_func.c
	gcc -c sum_func.c

mean_func.o: mean_func.c 
	gcc -c mean_func.c

clean:
	rm -rf *.exe *.o *.h.gch *.c~ makefile~ *.h~ 

