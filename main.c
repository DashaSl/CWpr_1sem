#include "mylib.h"

int main(){
	struct text a;
	get_text(&a);
	out_text(&a);
	printf("%d\n", a.size);
	free_text(&a);
	return 0;
}
