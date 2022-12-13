#include "mylib.h"

int main(){
	struct word a, b;
	get_word(&a);
	get_word(&b);
	printf("%d\n", cmp_wrd(&a, &b));
	printf("%ls|%ls|\n", a.symb, b.symb);
	return 0;
}
