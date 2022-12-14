#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#define MW 10
#define AW 5
#define MS 20
#define AS 5
#define MT 30
#define AT 10

struct word{
        wchar_t* symb;
        int size;
        int punct;//0-no 1-comma 2-point
};

struct sentence{
	struct word* sent;
	int size;
	int comma_num;
};

//функции сбора слов, их сравнения
void get_word(struct word* my_word);
int to_low(wchar_t** a, wchar_t**b);
int cmp_wrd(struct word* w1, struct word* w2);
//функции сбора слов, их сравнения
//
//функции по вводу, выводу, сравнению предложений
void out_sent(struct sentence* predlog);
void get_sentence(struct sentence* predlog);
void free_sent(struct sentence* predlog);
int cmp_sent(struct sentence* s1, struct sentence* s2);
//функции по вводу, выводу, сравнению предложений

