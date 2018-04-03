/*括号匹配的检验——假设表达式中允许包括两种括号：圆括号和方括号，其嵌套的顺序随意，即([]())或[([][])]等
  为正确的格式，[(])或([())等均为不正确格式。
  思路：借助于堆栈，将每个元素遍历一遍，根据一定的条件来确定是出栈还是入栈，
        如果最后栈为空，则括号是匹配的，否则不会匹配。
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "stack.h"

bool check(char *);
 
int main()  
{
	char exp[100];  
  
	printf("请输入一串括号：");
  	gets(exp);
    if (check(exp)) {
    	printf("括号匹配！\n");
    } else {
    	printf("括号不匹配！\n");
    }
}  

/*符号检验函数*/  
bool check(string exp)  
{  
    stackADT stack; /*堆栈指针*/
	string ptr;
	char top;
	bool isMatch;
	
	stack = NewStack();/*初始化堆栈*/
	
	while (*exp != '\0') {
		ptr = New(string); /*申请字符存储空间*/
		*ptr = *exp++; /*存储字符，同时后移字符指针*/
		if (*ptr != '(' && *ptr != ')' && *ptr != '[' && *ptr != ']') continue; /*忽略非括号*/ 
		top = IsemptyStack(stack) ? '\0' : *(char *)TopStack(stack); /*栈顶字符，若栈空则设为'\0'*/
		if (*ptr == ')' && top == '(' || *ptr == ']' && top == '[') { /*当前字符与栈顶字符配对*/ 
			ptr = PopStack(stack);
			free(ptr);
		} else { /*不配对*/ 
			PushStack(stack, ptr);
		}
	}
	isMatch = IsemptyStack(stack); /*当前栈是否为空——是则匹配，否则不匹配*/
	FreeStack(stack);
	return isMatch;
} 
  
