all: cw

cw: main.o word_in.o
	gcc main.o word_in.o -o cw

main.o: main.c mylib.h
	gcc -c main.c

word_in.o: word_in.c mylib.h
	gcc -c word_in.c

clean:
	rm -rf *.o 
