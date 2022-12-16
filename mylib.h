#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <math.h>

#define MW 10
#define AW 5
#define MS 20
#define AS 5
#define MT 10
#define AT 5

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

struct text{
	struct sentence* sents;
	int size;
};

//функции сбора слов, их сравнения
void get_word(struct word* my_word);
int cmp_wrd(struct word* w1, struct word* w2);
//функции сбора слов, их сравнения
//
//функции по вводу, выводу, сравнению предложений
void out_sent(struct sentence* predlog);
void get_sentence(struct sentence* predlog);
void free_sent(struct sentence* predlog);
int cmp_sent(struct sentence* s1, struct sentence* s2);
//функции по вводу, выводу, сравнению предложений
//
//функции по вводу, выводу, и фри текста
void get_text(struct text* essay);
void out_text(struct text* essay);
void free_text(struct text* essay);
//функции по вводу, выводу, и фри текста
//
//транслитерация
int translit_letter(wchar_t* str,int i, int size);
void trans_word(struct word* a);
void trans_sent(struct sentence* a);
void trans_text(struct text* a);
//транслитерация
//
//перевод в двоичную
int is_num(wchar_t* a);
void tobin(long int a, wchar_t* buff, int max_pow, int len);
void bin_word(struct word* a);
void bin_sent(struct sentence* a);
void bin_text(struct text* a);
//перевод в двоичную
//
//ПЕРЕВОД В ДВОИЧНУЮ КОТОРЫЙ ТРЕБОВАЛСЯ
int bin_dig(wchar_t* str,int i, int size);
void dbin_word(struct word* a);
void dbin_sent(struct sentence* a);
void dbin_text(struct text* a);
//ПЕРЕВОД В ДВОИЧНУЮ КОТОРЫЙ ТРЕБОВАЛСЯ
//
//удаление нечётных
int is_odd_word(struct word* a);
int is_odd_sent(struct sentence* a);
void del_odd_sent(struct text* a);
