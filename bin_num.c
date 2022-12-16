#include "mylib.h"

int bin_dig(wchar_t* str,int i, int size){ 
	wchar_t buff[2];
	buff[0] = str[i];
	buff[1] = L'\0';
        long int tmp = wcstol(buff, NULL, 10);
        switch(tmp){
		case 0:
			str[i] = L'0';
			return 1;
		case 1:
			str[i] = L'1';
			return 1;
		case 2:
			wmemmove(str+i+1, str+i, size-i+1);
			str[i] = L'1';
			str[i+1] = L'0';
			return 2;
		case 3:
			wmemmove(str+i+1, str+i, size-i+1);
                        str[i] = L'1';
                        str[i+1] = L'1';
			return 2;
		case 4:
                        wmemmove(str+i+2, str+i, size-i+1);
                        str[i] = L'1';
                        str[i+1] = L'0';
			str[i+2] = L'0';
			return 3;
		case 5:
			wmemmove(str+i+2, str+i, size-i+1);
                        str[i] = L'1';
                        str[i+1] = L'0';
                        str[i+2] = L'1';
			return 3;
		case 6:
			wmemmove(str+i+2, str+i, size-i+1);
                        str[i] = L'1';
                        str[i+1] = L'1';
                        str[i+2] = L'0';
			return 3;
		case 7:
                        wmemmove(str+i+2, str+i, size-i+1);
                        str[i] = L'1';
                        str[i+1] = L'1';
                        str[i+2] = L'1';
			return 3;
		case 8:
			wmemmove(str+i+3, str+i, size-i+1);
                        str[i] = L'1';
                        str[i+1] = L'0';
                        str[i+2] = L'0';
			str[i+3] = L'0';
			return 4;
		case 9:
			wmemmove(str+i+3, str+i, size-i+1);
                        str[i] = L'1';
                        str[i+1] = L'0';
                        str[i+2] = L'0';
                        str[i+3] = L'1';
			return 4;
	}
}


void dbin_word(struct word* a){
        int i = 0;
        int k;
        do{	
		if(iswdigit((*a).symb[i])){
                	k = bin_dig((*a).symb, i, (*a).size);
                	i+=k;
                	(*a).size += (k - 1);
		}else{
			i++;
		}
        }while((*a).symb[i] != L'\0');
}

void dbin_sent(struct sentence* a){
        for(int i = 0; i < (*a).size; i++){
                dbin_word((*a).sent+i);
        }
}
void dbin_text(struct text* a){
        for(int i = 0; i < (*a).size; i++){
                dbin_sent((*a).sents+i);
        }
}

