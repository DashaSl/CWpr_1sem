#include "mylib.h"

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

void trans_word(struct word* a){
	int i = 0;
	int k;
	do{
		k = translit_letter((*a).symb, i, (*a).size);
		i+=k;
		(*a).size += (k - 1);	
	}while((*a).symb[i] != L'\0');
}

void trans_sent(struct sentence* a){
	for(int i = 0; i < (*a).size; i++){
		trans_word((*a).sent+i);
	}
}
void trans_text(struct text* a){
	for(int i = 0; i < (*a).size; i++){
		trans_sent((*a).sents+i);
	}
}
