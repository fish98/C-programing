#include <stdio.h>
#include <stdlib.h>

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
	printf("Please enter num to save in new list \nEnter -1 to stop:\n ");
	Node *p;
	int tmp;
	scanf("%d", &tmp);

	while(tmp != -1){
		p = (Node *)malloc(sizeof(Node));
	    p -> num = tmp;
		if(l -> start){
			l -> end  = l -> end -> next = p;
			l -> end -> next = NULL;
		}
		else{
			l -> start = l -> end = p;
			l -> end -> next = NULL;
		} 
		scanf("%d", &tmp);
	}
	printf("Successfully input list\n");
	p = NULL;
}

int sizeList(Node *pNode) 
{
	int len = 0;
	while(pNode){
		len++;
		pNode = pNode->next;
	}
	return len;
}

void print(List * in){
    Node * tmp;
	tmp = in -> start;
	while(tmp){
		printf("%d ", tmp -> num);
		tmp = tmp -> next;
	}
	tmp = NULL;
	printf("\n");
}

void MergeList(List * in, List * out){
    Node * tmp;
	tmp = in -> start;
	if(out -> start){
		out -> end -> next = in -> start;
		out -> end = in -> end;
		// while(tmp){
        //     out -> end = out -> end -> next = tmp;			
		// 	tmp = tmp -> next;
		// 	out -> end -> next = NULL;
		// }
	}
	else{
         out -> start = in -> start;
		 out -> end = in -> end;
	}
}

void Bubble(Node* pNode) {
	if (pNode == NULL) {
		return ;
	}else{
		Node *pMove;
		pMove = pNode;
		
		//需要进行(n-1)次遍历,控制次数  
		
		int i, size = sizeList(pNode);
		for (i = 0; i < size; i++){
			while (pMove->next != NULL){
				if (pMove->num > pMove->next->num) {
					
					//交换这两个节点的值  
					
					int temp;
					temp = pMove->num;
					pMove->num = pMove->next->num;
					pMove->next->num = temp;
				}
				pMove = pMove->next;
			}
			
			//每次遍历结束，pMove重新移动到链表头部  
			
			pMove = pNode;
		}
	}
	
	return;
}

int main(){
	List l1, l2, final;
    l1.start = l2.start = final.start = NULL;
	l1.end = l2.end = final.end = NULL;
	GetList(&l1);
	GetList(&l2);
	MergeList(&l1, &final);
	MergeList(&l2, &final);
	Bubble(final.start);
//	print(&l1);
//	print(&l2);
	print(&final);
	return 0;	
} 
