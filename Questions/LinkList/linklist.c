#include <stdio.h>

/* Question: 已知两个非降序链表序列S1与S2，设计函数构造出S1与S2的并集新非降序链表S3 */

// Define Node and List 
typedef struct node{
	int num;
	struct node * next;
} Node;

typedef struct list{
	Node * start;
	Node * end; 
}List;

void GetList(List * l){
	printf("Please enter num to save in new list \n Enter -1 to stop\n: ");
	Node *p;
	int tmp;
	scanf("%d", &tmp);

	while(tmp != -1){
		p = (Node *)malloc(sizeof(Node));
	    p -> num = tmp;
		if(l -> start){
			l -> end  = l -> end -> next = p;
		}
		else{
			l -> start = l -> end = p;
		} 
		scanf("%d", &tmp);
	}
}

int main(){
	List * l1, *l2, * final;
    l1 -> start = l2 -> start = final -> start = NULL;
	l1 -> end = l2 -> end = final -> end = NULL;
	GetList(&l1);
	printf("%d", l1 -> start -> num);
	return 0;
} 
