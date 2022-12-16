all: cw

cw: main.o word_in.o sent_in.o text_in.o translit.o convert_bin.o
	gcc main.o word_in.o sent_in.o text_in.o translit.o convert_bin.o -o cw -lm

main.o: main.c mylib.h
	gcc -c main.c
word_in.o: word_in.c mylib.h
	gcc -c word_in.c
sent_in.o: sent_in.c mylib.h
	gcc -c sent_in.c
text_in.o: text_in.c mylib.h
	gcc -c text_in.c
translit.o: translit.c mylib.h
	gcc -c translit.c
convert_bin.o:
	gcc -c convert_bin.c
clean:
	rm -rf *.o 
