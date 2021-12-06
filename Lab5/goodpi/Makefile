pth_pi: pth_pi.c Get_args.c Serial_pi.c Thread_sum.c Usage.c Get_args.o Serial_pi.o Thread_sum.o Usage.o 
	 gcc -g -Wall -o pth_pi pth_pi.c Get_args.o Serial_pi.o Thread_sum.o -lm -lpthread

Get_args.o: Get_args.c
	gcc -c Get_args.c

Serial_pi.o: Serial_pi.c 
	gcc -c Serial_pi.c 
	
Thread_sum.o: Thread_sum.c 
	gcc -c Thread_sum.c 

Usage.o: Usage.c 
	gcc -c Usage.c

clean:
	rm -rf *.exe *.o *.h.gch *.c~ makefile~ *.h~