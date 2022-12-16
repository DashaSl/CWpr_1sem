#include "mylib.h"

int is_num(wchar_t* a){
	if(iswdigit(a[0]) || a[0] == L'-'){
		for(int i = 1; i < wcslen(a); i++){
			if(!iswdigit(a[i])){
				return 0;
			}
		}
		return 1;
	}else{
		return 0;
	}
}



void tobin(long int a, wchar_t* buff, int max_pow, int len){
	if(a >= 0){
		buff[0] = L'0';
	}else{
		buff[0] = L'1';
	}
	long int tmp = abs(a);
	for(int i = max_pow; i >= 0; i--){ //len = mp+3 => len - mp = 3 => len - mp - 2 = 1
		if(tmp >= pow(2, i)){
			tmp-= pow(2, i);
			buff[len-i-2] = L'1';
		}else{
			buff[len-i-2] = L'0';
		}
	}
	buff[len-1] = L'\0';

}


void bin_word(struct word* a){
	long int tmp;
	long int tmp2;
	int pow;
	wchar_t* buff;
	if(is_num((*a).symb)){
		tmp = wcstol((*a).symb, NULL, 10);
		if(tmp != 0){
			tmp2 = abs(tmp);
			pow = log2(tmp2);
        		buff = malloc(sizeof(wchar_t)*(pow+3));
			tobin(tmp, buff, pow, pow+3);
			free((*a).symb);
                	(*a).symb = buff;
		}

	}
}


void bin_sent(struct sentence* a){
	for(int i = 0; i < (*a).size; i++){
		bin_word((*a).sent+i);
	}
}

void bin_text(struct text* a){
        for(int i = 0; i < (*a).size; i++){
                bin_sent((*a).sents+i);
        }
}

