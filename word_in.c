#include "mylib.h"

void get_word(struct word* my_word){
	setlocale(LC_CTYPE, "");
	wchar_t* res_symb = malloc(sizeof(wchar_t)*MW);
	int punct = 0;
	
	wchar_t* trash; //for overload
	int k=0;
	
	wchar_t c;
	int i = 0;
	int no_error_flag = 1;

	do{			//to make spaces go away
		c = getwchar();
	}while(c == ' ');

	if(c == '\n'){
		free(res_symb);
		(*my_word).symb = NULL; 
		(*my_word).size = 0;
		(*my_word).punct = 2;
	}else{
		//собираем слово
		while(c != ' ' && c != ',' && c!= '.'){
			res_symb[i] = c;
			i++;
			c = getwchar();
			//конец случая переполнения
			if(i == MW + k-2){ //c - cкорее всего буква, что будет записана по индексу i => размер массива должен дыть мин i+1+1
				k+=AW;
				trash = realloc(res_symb, (MW+k)*sizeof(wchar_t));
				if(trash == NULL){
					free(res_symb);
					printf("недостаточно места для слова(нельзя сделать realloc), увеличьте MW & AW\n");
					no_error_flag = 0;
					break;
				}
				res_symb = trash;
			}
			//конец случая переполнения

		
		}
		//конец сбора слова
		if(no_error_flag){
			res_symb[i] = '\0';
			trash = realloc(res_symb, sizeof(wchar_t)*(4*i + 1)); //чтобы не париться с меммувом
				if(trash == NULL){
					printf("ошибка. слишком длинное слово\nНельзя и слова сказать. Блин, Ярик, memory потiк\n");
				}
			res_symb = trash;
			if(c == '.'){
				punct = 2;
			}
			if(c == ','){
				punct = 1;
			}

			(*my_word).symb = res_symb;
                        (*my_word).size = i;
                        (*my_word).punct = punct;

		}else{
			(*my_word).symb = NULL;
	                (*my_word).size = 0;
        	        (*my_word).punct = 2;

		}

	
	}
}

int cmp_wrd(struct word* w1, struct word* w2){
	int tmp = 1;
	if((*w1).punct != (*w2).punct){
		return 0;
	}
	int i = 0;
	while((*w1).symb[i] != L'\0' && (*w2).symb[i] != L'\0'){
		if(towlower((*w1).symb[i]) != towlower((*w2).symb[i])){
			tmp = 0;
			break;
		}
		i++;	
	}
	return tmp;
}

