all: cw

cw: main.o word_in.o sent_in.o text_in.o
	gcc main.o word_in.o sent_in.o text_in.o -o cw

main.o: main.c mylib.h
	gcc -c main.c

word_in.o: word_in.c mylib.h
	gcc -c word_in.c
sent_in.o: sent_in.c mylib.h
	gcc -c sent_in.c
text_in.o: text_in.c mylib.h
	gcc -c text_in.c
clean:
	rm -rf *.o 
