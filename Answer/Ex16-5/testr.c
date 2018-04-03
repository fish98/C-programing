#include "rational.h"

int main()
{
	rationalT sum, r;
	
	printf("This program adds a list of rational numbers.\n");
	printf("Signal end of list with a 0.\n");
	sum = CreateRational(0, 1);
	while (1) {
		printf("? ");
		GetRational(&r);
		if (r.num == 0) break;
		sum = AddRational(sum, r);
	}
	sum = ReduceRational(sum);
	printf("The Total is ");
	PrintRational(sum);
	printf("\n");
	
	return 0;
}

