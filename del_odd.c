#include "mylib.h"
int is_odd_word(struct word* a){
	long int tmp;
	wchar_t buff[2];
	buff[1] = L'\0';
	for(int i = 0; i < (*a).size; i++){
		if(iswdigit((*a).symb[i])){
			buff[0] = (*a).symb[i];
			tmp = wcstol(buff, NULL, 10);
			if(tmp % 2 == 1){
				return 1;
			}
		}
	}
	return 0;
}



int is_odd_sent(struct sentence* a){
	for(int i = 0; i < (*a).size; i++){
		if(is_odd_word((*a).sent+i)){
			return 1;
		}
	}
	return 0;
}

void del_odd_sent(struct text* a){
	int i = 0;
	for(int i = 0; i < (*a).size; i++){
		if(is_odd_sent((*a).sents+i)){
			free_sent((*a).sents+i);
			(*a).sents[i].sent = NULL;
			(*a).sents[i].size = 0;
			(*a).sents[i].comma_num  = -1;
		}
	}
}
