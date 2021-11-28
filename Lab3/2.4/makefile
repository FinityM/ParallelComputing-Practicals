mean_and_stddev: mean_and_stddev.c meanFunction.o sDeviate.o myfunctions.h
	gcc mean_and_stddev.c sDeviate.o meanFunction.o -o mean_and_stddev -lm

meanFunction.o: meanFunction.c
	gcc -c meanFunction.c

sDeviate.o: sDeviate.c
	gcc -c sDeviate.c
clean:
	rm -rf *.exe *.o *.h.gch
