#include "mylib.h"

int main(){
        struct text a;
        get_text(&a);
	del_odd_sent(&a);
	out_text(&a);
	free_text(&a);
	return 0;
}

