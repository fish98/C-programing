#include <stdio.h>
#include"graphics.h"
#include<math.h>

#define Pi 3.141592653589793

static void DrawPolarLine(double r, double theta)
{
	double radians;
	
	radians = theta / 180 * Pi;
	DrawLine(r * cos(radians) , r * sin(radians));
}

double len(int n,double line)
{
	if(n==0){
		return line;
	}else{
		return len(n-1,line)/3;
	}
}

void leg(double line, double t){
	DrawPolarLine(line, t);
	DrawPolarLine(line, t-60);
	DrawPolarLine(line, t+60);
	DrawPolarLine(line, t);	
}

void legloop(int n,double line, double t){
	if(n == 1){
		leg(line, t);
	}
	if(n >= 2){
		legloop(n-1, line, t);
		legloop(n-1, line, t-60);
		legloop(n-1, line, t+60);
		legloop(n-1, line, t);
	}
}
void DrawSnow(int n, double line)
{
	int i;
	for(i = 0; i < 3; i++){
		if(n == 0){
			DrawPolarLine(line, 120*i);
		}else{
			legloop(n, len(n,line),i*120);
		}		
	}
}

void Main()
{
	int n;
	double line;
	InitConsole(); 
	scanf("%d %lf",&n,&line);
	InitGraphics();	 
	MovePen(GetWindowWidth()/2-line/2,GetWindowHeight()/2-line/2/1.732);
	DrawSnow(n, line);
}
