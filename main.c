#include "mylib.h"

int main(){
	struct text a;
	get_text(&a);
	trans_text(&a);
	out_text(&a);
	free_text(&a);
	return 0;
}
