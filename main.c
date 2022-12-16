#include "mylib.h"

int main(){
        struct text a;
        get_text(&a);
	out_spc_text(&a);
	free_text(&a);
	return 0;
}

