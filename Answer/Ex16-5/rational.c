#include <stdio.h>
#include "rational.h"

rationalT CreateRational(int num, int den)
{
	rationalT r;

	r.num = num;
	r.den = den;
	return ReduceRational(r);
}

rationalT AddRational(rationalT r1, rationalT r2)
{
	rationalT r;
	
	r.num = r1.num * r2.den + r2.num * r1.den;
	r.den = r1.den * r2.den;
	return ReduceRational(r);	
}

rationalT MultiplyRational(rationalT r1, rationalT r2)
{
	rationalT r;
	
	r.num = r1.num * r2.num;
	r.den = r1.den * r2.den;
	return ReduceRational(r);
}

rationalT ReduceRational(rationalT r)
{
	int i;
	
	if (r.num == 0) return r;
	for (i = r.num; i >= 1; i--) {
		if (r.num % i == 0 && r.den % i == 0) {
			r.num /= i;
			r.den /= i;
			break;
		}
	}
	return r;
}

void GetRational(rationalT *r)
{
	int num, den;
	
	scanf("%d", &num);
	if (num == 0) {
		den = 1;	
	} else {
		scanf("/%d", &den); 
	}
	r->num = num;
	r->den = den; 
	*r = ReduceRational(*r);
	return;
}

void PrintRational(rationalT r)
{
	/*
	printf("%d"/%d", r.num, r.den);
	*/
	printf("%d", r.num);
	if (r.den != 1) printf("/%d", r.den);
	
	return;
}

