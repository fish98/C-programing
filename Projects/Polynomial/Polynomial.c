#include <stdio.h>
#include <stdlib.h>

/* ��������Ľṹ���뵥���� */

typedef struct node {
	int coef;
	int exp;
	struct node *next;
}Node;

typedef struct list {
	Node* head;
	Node* tail;
}List;

/* �������� */

void push(List* tmpList, int co, int ex);

// �������ڵ� 

void print(List *tmpList);

// ������� 

int printTerm(int co, int ex);

// �Զ���ʽ���в��� 

void operate(List* outlist, List* list1, List* list2);

void Add(List* outlist, List* list1, List* list2);
void Minus(List* outlist, List* list1, List* list2);
void Multiply(List* outlist, List* list1, List* list2);

//ð������ �Ѷ���ʽ�Ĵ����Ӵ�С���� 

void BubbleSort(Node* pNode);

// ��������ڵ����ĺ��� 

int sizeList(Node *pNode);

//�ϲ�ͬ���� 

void merge(Node *pNode);


/* �������������� */
void push(List* tmpList, int co, int ex) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->coef = co;
	p->exp = ex;
	p->next = NULL;
	Node* last = tmpList->tail;
	if(last){
		tmpList->tail = last->next = p;
	}else{
		tmpList->head = tmpList->tail = p;
	}
}

/* ������ð������Ӵ�С */

void BubbleSort(Node* pNode) {
	if (pNode == NULL) {
		//        printf("%s����ִ�У�����Ϊ�գ�ð������ʧ��\n",__FUNCTION__);  
		return ;
	}else{
		Node *pMove;
		pMove = pNode;
		
		//��Ҫ����(n-1)�α���,���ƴ���  
		
		int i, size = sizeList(pNode);
		for (i = 0; i < size; i++){
			while (pMove->next != NULL){
				if (pMove->exp < pMove->next->exp) {
					
					//�����������ڵ��ֵ  
					
					int temp;
					temp = pMove->exp;
					pMove->exp = pMove->next->exp;
					pMove->next->exp = temp;
					temp = pMove->coef;
					pMove->coef = pMove->next->coef;
					pMove->next->coef = temp;
				}
				pMove = pMove->next;
			}
			
			//ÿ�α���������pMove�����ƶ�������ͷ��  
			
			pMove = pNode;
		}
	}
	
	//    printf("%s����ִ�У�����ð���������\n",__FUNCTION__);  
	
	return;
}

/* ���õ��Ķ���ʽ������� */

void print(List *tmpList) 
{
	Node* p;
	int flag = 0;
	
	// ����Ƿ������ 
	
	int lengthp;
	int lengthList = sizeList(tmpList->head);
	for (p = tmpList->head; p; p = p->next) {
		lengthp	= sizeList(p);
		if(p->coef){
			if((lengthp != lengthList) && (p->coef > 0)){
			    printf("+");
		    }
			flag = printTerm(p->coef, p->exp);
	    }
	} 
	if(!flag){
		printf("0\n");
	}
}

/* ���ÿһ�� */ 

int printTerm(int co, int ex){
	if(co != 1 && co != -1){
		printf("%d", co);
	}else if(co == -1 && ex != 0){
		printf("-");
	}
	if(ex != 1 && ex != 0){
		printf("x^%d", ex);
	}else if(ex == 1){
		printf("x");
	}else if(co == 1 || co == -1){
		printf("%d", co);
	}
	return 1;
}

/* ��������ȵĺ��� */

int sizeList(Node *pNode) 
{
	int len = 0;
	while(pNode){
		len++;
		pNode = pNode->next;
	}
	return len;
}

/* �ϲ�ͬ���� */

void merge(Node *pNode) 
{
	int size = sizeList(pNode);
	int i;
	for (i = 0; i < size-1; i++){
		if(pNode->exp == pNode->next->exp){
			pNode->coef = pNode->coef + pNode->next->coef;
			pNode->next = pNode->next->next;
		}else{
			pNode = pNode->next;
		}
	}
}

/* ��ȡ��������������� */

void operate(List* outlist, List* list1, List* list2) 
{
	printf("��������Ҫ������ָ� (+ / - / * )\n");
	char op;
	
	// operator ��Ȼ��һ�������ʣ����� 
	 
	scanf("%c", &op);
	while (op == 10){
		scanf("%c", &op);
	}
	switch(op){
		case '+': Add(outlist, list1, list2);
		break;
		case '-': Minus(outlist, list1, list2);
		break;
		case '*': Multiply(outlist, list1, list2);
		break;
		default : printf("������Ϸ��������\n");
		operate(outlist, list1, list2);
	}
}

/* �ӷ����� */

void Add(List* outlist, List* list1, List* list2) 
{
	
	//��list1��list2����outlist�� 
	
	int size1 = sizeList(list1->head);
	int size2 = sizeList(list2->head);
	int i;
	Node *p = list1->head;
	for (i = 0; i < size1 ; i++ ){
		push(outlist, p->coef, p->exp);
		p = p->next;
	}
	p = list2->head;
	for (i = 0; i < size2 ; i++ ){
		push(outlist, p->coef, p->exp);
		p = p->next;
	}
	BubbleSort(outlist->head);
	merge(outlist->head);
}

/* �������� */

void Minus(List* outlist, List* list1, List* list2) 
{
	int size1 = sizeList(list1->head);
	int size2 = sizeList(list2->head);
	int i;
	Node *p = list1->head;
	for (i = 0; i < size1 ; i++ ) 
	{
		push(outlist, p->coef, p->exp);
		p = p->next;
	}
	p = list2->head;
	for (i = 0; i < size2 ; i++ ) 
	{
		push(outlist, -p->coef, p->exp);
		p = p->next;
	}
	BubbleSort(outlist->head);
	merge(outlist->head);
}

/* �˷����� */

void Multiply(List* outlist, List* list1, List* list2) 
{
	int i,j;
	int size1 = sizeList(list1->head);
	int size2 = sizeList(list2->head);
	Node *p = list1->head, *q;
	for (i = 0; i < size1; i++){
		q = list2->head;
		for (j = 0; j < size2; j++) 
		{
			push(outlist, p->coef*q->coef, p->exp+q->exp);
			q = q->next;
		}
		p = p->next;
	}
	BubbleSort(outlist->head);
	merge(outlist->head);
}

int main() 
{
	List list1, list2, outlist;
	
	// ������������ 
	
	int n, i;
	
	// forѭ��ʹ�õĲ������� 
	
	int co = 1, exp = 1;
	
	// �������ʽ�ĵ������ϵ����ָ�� 
	
	/* ��ʼ������ */
	
	list1.head = list1.tail = NULL;
	list2.head = list2.tail = NULL;
	outlist.head = outlist.tail = NULL;
	printf("�������ʽ1��(��ʽ��a b, ��0 0����)\n");
	
	// ����������� 
	
	while (co || exp){
		scanf("%d %d", &co, &exp);
		push(&list1, co, exp);
	}
	BubbleSort(list1.head);
	merge(list1.head);
	print(&list1);
	printf("\n");
	
	// �����ŵ��ֶ����� 
	
	co = exp = 1;
	printf("�������ʽ2��(��ʽ��a b, ��0 0����)\n");
	while (co || exp){
		scanf("%d %d", &co, &exp);
		push(&list2, co, exp);
	}
	BubbleSort(list2.head);
	merge(list2.head);
	print(&list2);
	printf("\n");
	
	//�����ŵ��ֶ�����
	
	/* ��ȡ�������� */
	
	operate(&outlist, &list1, &list2);
	print(&outlist);
	system("pause");
	return 0;
}
