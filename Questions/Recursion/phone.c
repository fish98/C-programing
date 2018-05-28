#include<stdio.h>
#include<stdlib.h>

char change(char ch)
{
	switch(ch){
		case 50:return 65;break;
		case 51:return 68;break;
		case 52:return 71;break;
		case 53:return 74;break;
		case 54:return 77;break;
		case 55:return 80;break;
		case 56:return 84;break;
		case 57:return 87;break;
		default:return ch;break;
	}
}

void Listmnemonics(char* str)
{
	int i,j,k;
	if ("2"<=str[2]<="9"&&"2"<=str[1]<="9"&&"2"<=str[0]<="9"){
		for (i = 0;i < 3;i++){
			for (j = 0;j < 3;j++){
				for (k = 0;k < 3;k++){
					printf("%c%c%c ",change(str[0])+i,change(str[1])+j,change(str[2])+k);
				}
			}
			printf("\n");
		}	
	}
	if ("0"<=str[2]<="1"&&"2"<=str[1]<="9"&&"2"<=str[0]<="9"){
		for (i = 0;i < 3;i++){
			for (j = 0;j < 3;j++){
				
				printf("%c%c%c ",change(str[0])+i,change(str[1])+j,change(str[2]));
				
			}
			printf("\n");
		}	
	}
	if ("2"<=str[2]<="9"&&"0"<=str[1]<="1"&&"2"<=str[0]<="9"){
		for (i = 0;i < 3;i++){
			for (k = 0;k < 3;k++){
				
				printf("%c%c%c ",change(str[0])+i,change(str[1]),change(str[2])+k);
				
			}
			printf("\n");
		}	
	}
		if ("2"<=str[2]<="9"&&"2"<=str[1]<="9"&&"0"<=str[0]<="1"){
		for (j = 0;j < 3;j++){
			for (k = 0;k < 3;k++){
				
					printf("%c%c%c ",change(str[0]),change(str[1])+j,change(str[2])+k);
				
			}
			printf("\n");
		}	
	}
		if ("0"<=str[2]<="1"&&"0"<=str[1]<="1"&&"2"<=str[0]<="9"){
		for (i = 0;i < 3;i++){
			
				
				printf("%c%c%c ",change(str[0])+i,change(str[1]),change(str[2]));
				
			
			printf("\n");
		}	
	}
	if ("2"<=str[2]<="9"&&"0"<=str[1]<="1"&&"0"<=str[0]<="1"){
		for (k = 0;k < 3;k++){
			
				
				printf("%c%c%c ",change(str[0]),change(str[1]),change(str[2])+k);
				
			
			printf("\n");
		}	
	}
		if ("0"<=str[2]<="1"&&"2"<=str[1]<="9"&&"0"<=str[0]<="1"){
		for (j = 0;j < 3;j++){
			
				
					printf("%c%c%c ",change(str[0]),change(str[1])+j,change(str[2]));
				
			
			printf("\n");
		}	
	}
	if ("0"<=str[2]<="1"&&"0"<=str[1]<="1"&&"0"<=str[0]<="1"){
		
			
				
					printf("%c%c%c ",change(str[0]),change(str[1]),change(str[2]));
				
			
			printf("\n");
			
	}
}

int main() 
{
	char str[3];
	int i;
	for(i = 0;i < 3;i++){
		scanf("%c", &str[i]);
	}
	Listmnemonics(str);
	return 0;
}
