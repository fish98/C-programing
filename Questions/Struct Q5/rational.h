#ifndef   __RATIONAL_H__
#define   __RATIONAL_H__

  typedef struct fish{
  	int num;
  	int den;
  } rationalT; 
  
  double CreateRational(int num, int den){
  	return num/den;
  }
  
  rationalT AddRational(rationalT r1, rationalT r2){
  	rationalT ha;
  	ha.num = r1.num * r2.den + r1.den * r2.num;
  	ha.den = r1.den * r2.den;
  	return ha;
  }
  
  rationalT MultiplyRational(rationalT r1, rationalT r2){
  	rationalT ha;
    ha.num = r1.num * r2.num;
    ha.den = r1.den * r2.den;
    return ha;
  }

  int GetRational(rationalT *r){
    scanf("%d/%d", &(r->num), &(r->den));
    return r -> num;
  }
  
  void PrintRational(rationalT r){
    int c, min;
   
    if(r.num > r.den){
      min = r.den;
    } else{
      min = r.num;
    }
    for(c = 2; c <= min; c++){
      if(!(r.num % c) && !(r.den % c)){
        r.num /= c;
        r.den /= c;
      }
    } 
    if(r.den == 1){
    	printf("%d\n", r.num);
    } 
    else{
	printf("%d/%d\n", r.num, r.den);
  }
}
  
#endif
