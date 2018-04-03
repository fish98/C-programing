/*����ƥ��ļ��顪��������ʽ����������������ţ�Բ���źͷ����ţ���Ƕ�׵�˳�����⣬��([]())��[([][])]��
  Ϊ��ȷ�ĸ�ʽ��[(])��([())�Ⱦ�Ϊ����ȷ��ʽ��
  ˼·�������ڶ�ջ����ÿ��Ԫ�ر���һ�飬����һ����������ȷ���ǳ�ջ������ջ��
        ������ջΪ�գ���������ƥ��ģ����򲻻�ƥ�䡣
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "stack.h"

bool check(char *);
 
int main()  
{
	char exp[100];  
  
	printf("������һ�����ţ�");
  	gets(exp);
    if (check(exp)) {
    	printf("����ƥ�䣡\n");
    } else {
    	printf("���Ų�ƥ�䣡\n");
    }
}  

/*���ż��麯��*/  
bool check(string exp)  
{  
    stackADT stack; /*��ջָ��*/
	string ptr;
	char top;
	bool isMatch;
	
	stack = NewStack();/*��ʼ����ջ*/
	
	while (*exp != '\0') {
		ptr = New(string); /*�����ַ��洢�ռ�*/
		*ptr = *exp++; /*�洢�ַ���ͬʱ�����ַ�ָ��*/
		if (*ptr != '(' && *ptr != ')' && *ptr != '[' && *ptr != ']') continue; /*���Է�����*/ 
		top = IsemptyStack(stack) ? '\0' : *(char *)TopStack(stack); /*ջ���ַ�����ջ������Ϊ'\0'*/
		if (*ptr == ')' && top == '(' || *ptr == ']' && top == '[') { /*��ǰ�ַ���ջ���ַ����*/ 
			ptr = PopStack(stack);
			free(ptr);
		} else { /*�����*/ 
			PushStack(stack, ptr);
		}
	}
	isMatch = IsemptyStack(stack); /*��ǰջ�Ƿ�Ϊ�ա�������ƥ�䣬����ƥ��*/
	FreeStack(stack);
	return isMatch;
} 
  
