#include "mylib.h"

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
		size+=(*a).sent[i].size;
	}
	size += (*a).size-1;
       	size += (*a).comma_num;	

	wchar_t* buff = malloc(sizeof(wchar_t)*size);
	int count = 0;
	
	struct word tmp;	
	for(int i = 0; i < (*a).size; i++){
		tmp = (*a).sent[i];
		for(int j = 0; j < tmp.size; j++){

			if(!iswalnum(tmp.symb[j])){
				buff[count] = tmp.symb[j];
				count++;
			}
		}
	}
	for(int i = 0; i < (*a).size - 1; i++){
		buff[count] = L' ';
		count++;
	}
	for(int i = 0; i < (*a).comma_num; i++){
		buff[count] = L',';
		count++;
	}

	buff[count] = L'\0';
	qsort(buff, count, sizeof(wchar_t), cmp_wc);
	printf("%ls= %ld(количество специальных символов)\n", buff, wcslen(buff));
	free(buff);

}

void out_spc_text(struct text* a){
	for(int i = 0; i < (*a).size; i++){
		printf("специальные символы %d предлжения: ", i+1);
		out_spc_sent((*a).sents+i);
	}
}
