#include "iof.h"
#include "func.h"

int main(){
	setlocale(LC_CTYPE, "");
	struct text tmp;
	printf("\n\n\nКурсовая работа по программированию, 1 семестр.\nВыполнена Слабновой Дарьей 2381\n\n\nВведите текст.\nНе забывайте о красной строке(пробеле) перед первым предложением абзаца.\nТекст должен заканчиваться терминальным предложением \"ENDENDEND.\"\n");
	get_text(&tmp);
	printf("\n\n\nвыберите действие:\n1 - транслитерировать текст\n2 - вывести специальные символы каждого предложения в порядке уменьшения кода\n3 - заменить все цифры в тексте их двоичным кодом\n4 - Удалить все предложения в которых есть нечетные цифры\n");
	wchar_t c;
	wchar_t trash;
	trash = getwchar();
	c = getwchar();
	do{
		trash = getwchar();
	}while(trash != L'\n');

	switch(c){
		case L'1':
			trans_text(&tmp);
			out_text(&tmp);
			break;
		case L'2':
			out_spc_text(&tmp);
			break;
		case L'3':
			dbin_text(&tmp);
			out_text(&tmp);
			break;
		case L'4':
			del_odd_sent(&tmp);
			out_text(&tmp);
			break;
		default:
			printf("Введите предложенное число.\n");
	}
	free_text(&tmp);
	printf("\n\nСпасибо за внимание!\n\n\n");
	return 0;
}
