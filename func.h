#ifndef JUST_HERE 

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

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

void free_sent(struct sentence* predlog);
#endif

int translit_letter(wchar_t* str,int i, int size);
int trans_word(wchar_t** a, int* size);
int trans_sent(struct sentence* a);
void trans_text(struct text* a);

int cmp_wc(const void* a, const void* b);
void out_spc_sent(struct sentence* a);
void out_spc_text(struct text* a);

int bin_dig(wchar_t* str,int i, int size);
int dbin_word(struct word* a);
int dbin_sent(struct sentence* a);
void dbin_text(struct text* a);

int is_odd_word(struct word* a);
int is_odd_sent(struct sentence* a);
void del_sent_ind(struct text*a, int ind);
void del_odd_sent(struct text* a);
