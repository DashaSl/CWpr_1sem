#include "iof.h"

//finish sentence: "ENDENDEND." - punct = 2

int get_word(struct word* my_word){
        setlocale(LC_CTYPE, "");
        wchar_t* res_symb = malloc(sizeof(wchar_t)*MW);
        int punct = 0;

        wchar_t* trash; //for overload
        int k=0;

        wchar_t c;
        int i = 0;
        int no_error_flag = 1;
	static int err_wrd_num = 0;

        do{                     //to make spaces go away
                c = getwchar();
        }while(c == ' ');

        
         //собираем слово
         while(c != ' ' && c != ',' && c!= '.'){
             	res_symb[i] = c;
             	i++;
              	c = getwchar();
        	if(i == MW + k-4){ //c - cкорее всего буква, что будет записана по индексу i => размер массива должен дыть мин i+1+1 !+3 символа на транслитерацию
                       	k+=AW;
                       	trash = realloc(res_symb, (MW+k)*sizeof(wchar_t));
                       	if(trash == NULL){
                    		printf("%sнеудалось ввести слово №%d%s\n", RED, err_wrd_num ,NONE);
				i--;
                               	no_error_flag = 0;
                                break;
                      	}
                    	res_symb = trash;
          	}
                        //конец случая переполнения


   	}
        
	my_word->size = i;
	res_symb[i] = '\0';
	my_word->symb = res_symb;
      	if(no_error_flag){
             	if(c == '.'){
                      	punct = 2;
              	}
           	if(c == ','){
                   	punct = 1;
           	}
           	my_word->punct = punct;

       	}else{
             	my_word->punct = 2;

      	}
	err_wrd_num++;
	return no_error_flag;

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



int get_sentence(struct sentence* predlog){
	setlocale(LC_CTYPE, "");
        struct word* res = malloc(sizeof(struct word)*MS);
        int i = 0;

        struct word* trash;
        int k = 0;
        int no_error_flag = 1;
	static int num_err = 0;

	wchar_t c = getwchar();
	if(c == ' '){
		predlog->paragraph = 0;
	}else{
		predlog->paragraph = 1;
	}

        do{
                if(i == MS+k-1){
                        k+=AS;
                        trash = realloc(res, (MS+k)*sizeof(struct word));
                        if(trash == NULL){
                                fprintf(stderr, "\n%sпоследнее введённое слово - %ls, в предложении №%d%s\n", RED, (res[i-1]).symb, num_err, NONE);
                                no_error_flag = 0;
                                break;
                        }
                        res = trash;

                }
                no_error_flag = get_word(&res[i]);
		if(!no_error_flag){
			break;
		}
                i++;
        }while((res[i-1]).punct != 2);
	
	char f;
	if(!no_error_flag){
		do{
			f = getchar();
		}while(c != '.');	
	}

       	predlog->sent = res;
       	predlog->size = i;

	num_err++;
	return no_error_flag;
}

void out_sent(struct sentence* predlog){
	setlocale(LC_CTYPE, "");
        struct word tmp;
        for(int i = 0; i < predlog->size; i++){
                tmp = (predlog->sent)[i];
                if(tmp.punct == 1){
                        printf("%ls, ", tmp.symb);
                }else if(tmp.punct == 2){
                        printf("%ls.", tmp.symb);
                }else{
                        printf("%ls ", tmp.symb);
                }
        }
}

void free_sent(struct sentence* predlog){
        for(int i = 0; i < predlog->size; i++){
                free(((*predlog).sent)[i].symb);
        }
        free(predlog->sent);

}


int cmp_sent(struct sentence* s1, struct sentence* s2){
        if(s1->size != s2->size){
                return 0;
        }else{
                for(int i = 0; i < s1->size; i++){
                        if(!cmp_wrd(s1->sent + i, s2->sent + i)){
                                return 0;
                        }
                }

                return 1;
        }


}

void get_text(struct text* essay){
        struct sentence* res = malloc(sizeof(struct sentence)*MT);
        int i = 0;
        struct sentence tmp = {NULL, 0, 0};
        int is_same_flag = 0;

	struct word term_w = {L"ENDENDEND", 9, 2};
	struct word t = {NULL, 0, 0};
	struct sentence term_s = {&term_w, 1, 0};

        int k = 0;
        struct sentence* trash;
        int no_error_flag = 1;


        do{
                is_same_flag = 0;

                if(i == MT+k){
                        k+=AT;
                        trash = realloc(res, sizeof(struct sentence)*(MT+k));
                        if(trash == NULL){
                                fprintf(stderr ,"\nпоследнее введённое предложение - %d\n", i);
                                no_error_flag = 0;
                                break;
                        }
                        res = trash;
                }

                no_error_flag = get_sentence(&tmp);

		if(!no_error_flag){
			break;
		}

                for(int l = 0; l < i; l++){
                        if(cmp_sent(&tmp, &res[l])){
                                is_same_flag = 1;
                                break;
                        }
                }

                if(is_same_flag){
                        free_sent(&tmp);
                }else{
                        res[i] = tmp;
                        i++;
                }

        }while(!cmp_sent(&term_s, &res[i-1]) && no_error_flag);
	
	if(no_error_flag){
        	free_sent(&(res[i-1]));
        	i--;
	}else{
		do{
			free(t.symb);
			get_word(&t);
		}while(!cmp_wrd(&term_w, &t));
		free(t.symb);
	}

      	(*essay).sents = res;
      	(*essay).size = i;
}

void out_text(struct text* essay){
        for(int i = 0; i < (*essay).size; i++){
		if((essay->sents)[i].paragraph){
			printf("\n");
		}
		printf(" ");
                out_sent((*essay).sents+i);
        }
        printf("\n");
}

void free_text(struct text* essay){
        for(int i = 0; i < (*essay).size; i++){
                free_sent((*essay).sents+i);
        }
        free((*essay).sents);
}

