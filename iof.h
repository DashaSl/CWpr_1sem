#define JUST_HERE

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#define MW 6
#define AW 2
#define MS 15
#define AS 3
#define MT 10
#define AT 3

#define RED "\033[0;31m"
#define NONE   "\033[0m"

struct word{
        wchar_t* symb; // the word itself
        int size; //number of letters
        int punct;//0-no 1-comma 2-point
};

struct sentence{
        struct word* sent; //pointer to the first element of dynamic array of words
        int size; //number of words
        int paragraph; //0 - old paragraph, 1 - new paragraph
};

struct text{
        struct sentence* sents; //pointer to the 
        int size;
};

//функции сбора слов, их сравнения
int get_word(struct word* my_word);
int cmp_wrd(struct word* w1, struct word* w2);
//функции сбора слов, их сравнения
//
//функции по вводу, выводу, сравнению предложений
void out_sent(struct sentence* predlog);
int get_sentence(struct sentence* predlog);
void free_sent(struct sentence* predlog);
int cmp_sent(struct sentence* s1, struct sentence* s2);
//функции по вводу, выводу, сравнению предложений
//
//функции по вводу, выводу, и фри текста
void get_text(struct text* essay);
void out_text(struct text* essay);
void free_text(struct text* essay);
//функции по вводу, выводу, и фри текста

