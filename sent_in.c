#include "mylib.h"

void get_sentence(struct sentence* predlog){
	struct word* res = malloc(sizeof(struct word)*MS);
	int comma = 0;
	int i = 0;

	struct word* trash;
	int k = 0;
	int no_error_flag = 1;
	
	do{
		if(i == MS+k-1){
			k+=AS;
			trash = realloc(res, (MS+k)*sizeof(struct word));
			if(trash == NULL){
				for(int l = 0; l < i; l++){
					free((res[l]).symb);
				}
				free(res);
				printf("Место в куче пустеет, милорд. Увеличьте MS & AS\n");
				no_error_flag = 0;
				break;
			}
			res = trash;
		
		}
		get_word(&res[i]);
		i++;
		if((res[i-1]).punct == 1){
			comma++;
		}
	}while((res[i-1]).punct != 2);

	if(no_error_flag && (res[i-1]).symb != NULL){
		(*predlog).sent = res;
		(*predlog).size = i;
		(*predlog).comma_num = comma;
	}else{
		(*predlog).sent = NULL;
                (*predlog).size = 0;
		(*predlog).comma_num = 0;
	}
}

void out_sent(struct sentence* predlog){
	struct word tmp;
	for(int i = 0; i < (*predlog).size; i++){
		tmp = ((*predlog).sent)[i];
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
	for(int i = 0; i < (*predlog).size; i++){
		free(((*predlog).sent)[i].symb);
	}
	free((*predlog).sent);

}


int cmp_sent(struct sentence* s1, struct sentence* s2){
	if((*s1).size != (*s2).size){
		return 0;
	}else{
		for(int i = 0; i < (*s1).size; i++){
			if(!cmp_wrd(&((*s1).sent[i]), &((*s2).sent[i]))){
				return 0;
			}
		}
		return 1;
	}


}
