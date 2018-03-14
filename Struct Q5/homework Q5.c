#include <stdio.h>
#include <math.h>
#include "rational.h"

int main() {
	rationalT a, b, sum;
    while(GetRational(&a)){
	    GetRational(&b);
	    sum = AddRational(a,b);
	}
	PrintRational(sum);	
	return 0; 
} 
