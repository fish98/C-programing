#include<stdio.h>

typedef struct _node {
	int value;
	struct _node *next;
} Node;

typedef struct _list {
	Node* head;
	Node* tail;
} List;

void add(List* pList, int number);
void print(List *pList);

int main()
{
	Node* head = NULL;
	List list1, list2, list;
	int number;
	list1.head = list1.tail = NULL;
	// scanf list1,list2
	do{
		scanf("%d", &number);
		if(number != -1) {
			add(&list1, number);
		}
	}while(number != -1);
	list2.head = list2.tail = NULL;
	do{
		scanf("%d", &number);
		if(number != -1) {
			add(&list2, number);
		}
	}while(number != -1);
	//make the new list
	Node* p, *q;
	list.head = list.tail = NULL;
	p =list1.head;
	q =list2.head;
	if (list1.tail->value<list2.tail->value){
		while(p){
			if(p->value < q->value){
				add(&list, p->value);
				p = p->next;
			}else{
				add(&list, q->value);
				q = q->next;
			}
		}
		while(q){
			add(&list, q->value);
			q = q->next;
		}
	}else{
		while(q){
			if(p->value < q->value){
				add(&list, p->value);
				p = p->next;
			}else{
				add(&list, q->value);
				q = q->next;
			}
		}
		while(p){
			add(&list, p->value);
			p = p->next;
		}
	}
	print(&list);
	return 0;
}

void add(List* pList, int number)
{
	Node*p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	Node*last = pList->tail;
	if( last ) {
		pList->tail = last->next = p;	
	} else {
		pList->head = pList->tail = p;
	}
}

void print(List *pList){
	Node* p;
	for( p = pList->head; p; p = p->next){
		printf("%d ", p->value);
	}
	printf("\n");
}
