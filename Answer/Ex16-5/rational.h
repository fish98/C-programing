/*
 * File: rational.h
 * Version: 1.0
 * Last modified on Mon Mar 19 23:41:22 2018 by Xu Duanqing 
 * -----------------------------------------------------
 * This interface provides several functions for simple 
 * opertions on rational numbers.
 */

#ifndef _rational_h
#define _rational_h

#include <stdio.h>

typedef struct {
	int num;
	int den;
} rationalT;

rationalT CreateRational(int num, int den);
rationalT AddRational(rationalT r1, rationalT r2);
rationalT MultiplyRational(rationalT r1, rationalT r2);
rationalT ReduceRational(rationalT r);
void GetRational(rationalT *r);
void PrintRational(rationalT r);

#endif
 
 
