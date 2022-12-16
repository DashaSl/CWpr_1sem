#include "mylib.h"

void get_text(struct text* essay){
	struct sentence* res = malloc(sizeof(struct sentence)*MT);
	int i = 0;
	struct sentence tmp = {NULL, 0, 0};
	int is_same_flag = 0;

	int k = 0;
	struct sentence* trash;
	int no_error_flag = 1;

	do{
		is_same_flag = 0;

		if(i == MT+k){
			k+=AT;
			trash = realloc(res, sizeof(struct sentence)*(MT+k));
			if(trash == NULL){
				for(int l = 0; l < i; l++){
					free_sent(&res[l]);
				}
				free(res);
				printf("А вы не устали, набирая столь длинный текст?\n");
				no_error_flag = 0;
				break;
			}
			res = trash;
		}
		
		get_sentence(&tmp);

		for(int l = 0; l < i; l++){
			if(cmp_sent(&tmp, &res[l])){
				is_same_flag = 1;
				break;
			}
		}
		if(is_same_flag){
			free_sent(&tmp);
			tmp.sent = NULL;
			tmp.size = 0;
			tmp.comma_num = 0;
		}else{						
			res[i] = tmp;
			i++;
		}
	}while(res[i-1].sent != NULL);

	free_sent(&(res[i-1]));
	i--;

	if(no_error_flag){
		(*essay).sents = res;
		(*essay).size = i;
	}else{
		(*essay).sents = NULL;
		(*essay).size = 0;
	}
}

void out_text(struct text* essay){
	for(int i = 0; i < (*essay).size; i++){
		if((*essay).sents[i].comma_num != -1){
			out_sent((*essay).sents+i);
			printf(" ");
		}
	}
	printf("\n");
}

void free_text(struct text* essay){
	for(int i = 0; i < (*essay).size; i++){
		if((*essay).sents[i].comma_num != -1){
			free_sent((*essay).sents+i);
		}
	}
	free((*essay).sents);
}
