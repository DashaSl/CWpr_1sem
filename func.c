#include "func.h"

int translit_letter(wchar_t* str,int i, int size){ //транслит iый символ строки str; 0 - удалили символ 1 - заменили одной буквой 2 -заменили двумя буквами
	setlocale(LC_CTYPE, "");
	wchar_t tmp = str[i];
	switch(towlower(tmp)){
		//буквы от А до Е
		case L'а':
			if(iswupper(tmp)){
                                str[i] = L'A';
                        }else{
                                str[i] = L'a';
                        }
                        return 1;
		case L'б':
                        if(iswupper(tmp)){
                                str[i] = L'B';
                        }else{
                                str[i] = L'b';
                        }
                        return 1;
		case L'в':
                        if(iswupper(tmp)){
                                str[i] = L'V';
                        }else{
                                str[i] = L'v';
                        }
                        return 1;
		case L'г':
			if(iswupper(tmp)){
				str[i] = L'G';
			}else{
				str[i] = L'g';
			}
			return 1;
		case L'д':
                        if(iswupper(tmp)){
                                str[i] = L'D';
                        }else{
                                str[i] = L'd';
                        }
                        return 1;
		case L'е':
                        if(iswupper(tmp)){
                                str[i] = L'E';
                        }else{
                                str[i] = L'e';
                        }
                        return 1;
		//буквы от Ё до К
		case L'ё':
                        if(iswupper(tmp)){
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'Y';
                                str[i+1] = L'o';
                        }else{
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'y';
                                str[i+1] = L'o';

                        }
                        return 2;
		 case L'ж':
                        if(iswupper(tmp)){
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'Z';
                                str[i+1] = L'h';
                        }else{
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'z';
                                str[i+1] = L'h';

                        }
                        return 2;
		case L'з':
                        if(iswupper(tmp)){
                                str[i] = L'Z';
                        }else{
                                str[i] = L'z';
                        }
                        return 1;
		case L'и':
                        if(iswupper(tmp)){
                                str[i] = L'I';
                        }else{
                                str[i] = L'i';
                        }
                        return 1;
		case L'й':
                        if(iswupper(tmp)){
                                str[i] = L'J';
                        }else{
                                str[i] = L'j';
                        }
                        return 1;
		case L'к':
                        if(iswupper(tmp)){
                                str[i] = L'K';
                        }else{
                                str[i] = L'k';
                        }
                        return 1;
		//буквы от Л до Р
		case L'л':
                        if(iswupper(tmp)){
                                str[i] = L'L';
                        }else{
                                str[i] = L'l';
                        }
                        return 1;
                case L'м':
                        if(iswupper(tmp)){
                                str[i] = L'M';
                        }else{
                                str[i] = L'm';
                        }
                        return 1;
                case L'н':
                        if(iswupper(tmp)){
                                str[i] = L'N';
                        }else{
                                str[i] = L'n';
                        }
                        return 1;
                case L'о':
                        if(iswupper(tmp)){
                                str[i] = L'O';
                        }else{
                                str[i] = L'o';
                        }
                        return 1;
		case L'п':
                        if(iswupper(tmp)){
                                str[i] = L'P';
                        }else{
                                str[i] = L'p';
                        }
                        return 1;
                case L'р':
                        if(iswupper(tmp)){
                                str[i] = L'R';
                        }else{
                                str[i] = L'r';
                        }
                        return 1;
		//от С до ц
		case L'с':
                        if(iswupper(tmp)){
                                str[i] = L'S';
                        }else{
                                str[i] = L's';
                        }
                        return 1;
                case L'т':
                        if(iswupper(tmp)){
                                str[i] = L'T';
                        }else{
                                str[i] = L't';
                        }
                        return 1;
                case L'у':
                        if(iswupper(tmp)){
                                str[i] = L'U';
                        }else{
                                str[i] = L'u';
                        }
                        return 1;
                case L'ф':
                        if(iswupper(tmp)){
                                str[i] = L'F';
                        }else{
                                str[i] = L'f';
                        }
                        return 1;
                case L'х':
                        if(iswupper(tmp)){
                                str[i] = L'X';
                        }else{
                                str[i] = L'x';
                        }
                        return 1;
		case L'ц':
                        if(iswupper(tmp)){
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'C';
                                str[i+1] = L'z';
                        }else{
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'c';
                                str[i+1] = L'z';

                        }
                        return 2;
		//от Ч до ь
		case L'ч':
                        if(iswupper(tmp)){
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'C';
                                str[i+1] = L'h';
                        }else{
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'c';
                                str[i+1] = L'h';

                        }
                        return 2;
		case L'ш':
                        if(iswupper(tmp)){
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'S';
                                str[i+1] = L'h';
                        }else{
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L's';
                                str[i+1] = L'h';

                        }
                        return 2;
		case L'щ':
                        if(iswupper(tmp)){
                                wmemmove(str+i+2, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'S';
                                str[i+1] = L'h';
				str[i+2] = L'h';
                        }else{
                                wmemmove(str+i+2, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L's';
                                str[i+1] = L'h';
				str[i+2] = L'h';

                        }
                        return 3;
                case L'ъ':

                       	wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                       	str[i] = 39;
                       	str[i+1] = 39;

                        return 2;
		case L'ы':
                        if(iswupper(tmp)){
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'Y';
                                str[i+1] = 39;
                        }else{
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'y';
                                str[i+1] = 39;

                        }
                        return 2;
		case L'ь':
                                str[i] = 39;
                        return 1;
		// ... Э, Ю, Я!
		case L'э':
                        if(iswupper(tmp)){
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'E';
                                str[i+1] = 39;
                        }else{
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'e';
                                str[i+1] = 39;

                        }
                        return 2;
		case L'ю':
                        if(iswupper(tmp)){
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'Y';
                                str[i+1] = L'u';
                        }else{
                                wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'y';
                                str[i+1] = L'u';

                        }
                        return 2;
		case L'я':
			if(iswupper(tmp)){
				wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
				str[i] = L'Y';
				str[i+1] = L'a';
			}else{
				wmemmove(str+i+1, str+i, size-i+1); //+1, тк нужно скопировать '\0'
                                str[i] = L'y';
                                str[i+1] = L'a';

			}
			return 2;
		default:
			return 1;
	}

}

int trans_word(wchar_t** a, int* size){
	int i = 0;
	int k;

	static int num_err = 1;
	int err = 0;

	wchar_t* trash;
	do{
		k = translit_letter(*a, i, *size);
		i+=k;
		*size += (k - 1);
		if(k > 1){
			trash = malloc((*size + k + 2)*sizeof(wchar_t)); //+ (k-1) + 3
			if(trash == NULL){
				fprintf(stderr, "\n%sНеудалось транслитерировать слово - %ls%s\n", RED, *a, NONE);
				err = 1;
				break;
			}
			wcscpy(trash, *a);
			free(*a);
			*a = trash;
			
		}
			
	}while((*a)[i] != L'\0');
	num_err++;
	return err;
}

int trans_sent(struct sentence* a){
	int k = 0;
	for(int i = 0; i < (*a).size; i++){
		k = trans_word(&((((*a).sent)[i]).symb), &((((*a).sent)[i]).size));
		if(k) break;
	}
	return k;
}
void trans_text(struct text* a){
	int k = 0;
	for(int i = 0; i < (*a).size; i++){
		k = trans_sent((*a).sents+i);
		if(k) break;
	}
}



//2nd task
//
int cmp_wc(const void* a, const void* b){
	wchar_t* chr1 = (wchar_t*)a;
	wchar_t* chr2 = (wchar_t*)b;
	if((*chr1) > (*chr2)){
		return -1;
	}
	if((*chr1) < (*chr2)){
		return 1;
	}
	return 0;
}

void out_spc_sent(struct sentence* a){

	int size = 0;
	for(int i = 0; i < (*a).size; i++){
		size+=(a->sent)[i].size;
	}

	wchar_t* buff = malloc(sizeof(wchar_t)*(size+1));
	int count = 0;

	struct word tmp;
	for(int i = 0; i < (*a).size; i++){
		tmp = (*a).sent[i];
		for(int j = 0; j < tmp.size; j++){
		buff[count] = tmp.symb[j];
		count++;
			
		}
	}

	buff[count] = L'\0';
	qsort(buff, count, sizeof(wchar_t), cmp_wc);
	printf("%ls\n", buff);
	free(buff);

}

void out_spc_text(struct text* a){
	printf("\n");
	for(int i = 0; i < (*a).size; i++){
			printf("предложение №%d - ", i);
			out_spc_sent((*a).sents+i);
	}
}

//3rd task
//
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


int dbin_word(struct word* a){
	int i = 0;
        int k;

        static int num_err = 1;
        int err = 0;

        wchar_t* trash;
	do{	
		if(iswdigit((*a).symb[i])){
                	k = bin_dig((*a).symb, i, (*a).size);
                	i+=k;
                	(*a).size += (k - 1);
			if(k > 1){
				trash = malloc((a->size + 3)*(sizeof(wchar_t)));
				if(trash == NULL){
					fprintf(stderr, "\n%sНеудалось изменить цифру в слове - %ls%s\n", RED, (*a).symb, NONE);
					err = 1;
					break;
				}
				wcscpy(trash, a->symb);
                        	free(a->symb);
                        	a->symb = trash;
			}
		}else{
			i++;
		}
	}while((*a).symb[i] != L'\0');
	num_err++;
	return err;
           
}

int dbin_sent(struct sentence* a){
	int k = 0;
        for(int i = 0; i < (*a).size; i++){
                k = dbin_word((*a).sent+i);
		if(k) break;
        }
	return k;
}
void dbin_text(struct text* a){
	int k = 0;
        for(int i = 0; i < (*a).size; i++){
                k = dbin_sent((*a).sents+i);
		if(k) break;
        }
}

//4th
//
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

void del_sent_ind(struct text* a, int ind){
	free_sent((a->sents)+ind);
	for(int i = ind+1; i < a->size; i++){
		((*a).sents)[i-1] = ((*a).sents)[i];
	}
	(*a).size--;
}

void del_odd_sent(struct text* a){
	int i = 0;
	for(int i = 0; i < (*a).size; i++){
		if(is_odd_sent((*a).sents+i)){
			del_sent_ind(a, i);
		}
	}
}
