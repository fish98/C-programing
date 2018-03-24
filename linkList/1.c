#include <stdio.h>

#define LIST struct list

struct list{
	fish * head;
	fish * tail;
};

struct fish{
	int num;
	struct fish *next;
};

int main(){
    LIST *list1, *list2, *finallist;
    list1->
    int tmp;
    fish * point = (fish*)malloc(sizeof(fish));
    scanf("%d", &tmp);
    do{
    	add(&list1,tmp);
    }while(tmp != -1); 
//    printf("%d", List1->num);
    return 0;
}
