#include "mylib.h"

int main(){
	struct sentence a, b;
	get_sentence(&a);
	get_sentence(&b);
	out_sent(&a);
	out_sent(&b);
	printf("\ncommas_num = %d, size(num_of_words) = %d\n a == b: %d\n", a.comma_num, a.size, cmp_sent(&a, &b));
	free_sent(&a);
	free_sent(&b);
	return 0;
}
