all: cw

cw: main.o word_in.o sent_in.o text_in.o translit.o bin_num.o del_odd.o spec_symb.o
	gcc main.o word_in.o sent_in.o text_in.o translit.o bin_num.o del_odd.o spec_symb.o -o cw -lm

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
bin_num.o: bin_num.c mylib.h
	gcc -c bin_num.c
del_odd.o: del_odd.c mylib.h
	gcc -c del_odd.c
spec_symb.o: spec_symb.c mylib.h
	gcc -c spec_symb.c
clean:
	rm -rf *.o 
