#include <stdio.h>
#include <stdlib.h>
//Program to reverse linked list
struct node{
	int data;
	struct node *next;
};

void create(struct node **h){
	struct node *cur, *ptr;
	*h = NULL;
	for(int i = 0 ;i < 5;++i){
		cur = (struct node *)malloc(sizeof(struct node));
		cur->data = random()%11;
		cur->next = NULL;
		if(*h == NULL){
			*h = cur;
			ptr = cur;
		}
		else{
			ptr->next = cur;
			ptr = cur;
		}
	}
}

void display(struct node *h){
	struct node *ptr;
	for(ptr = h; ptr!= NULL; ptr = ptr->next){
		printf("%d ", ptr->data);
	}
	printf("\n");
}

void reverse(struct node **h){
	struct node *cur,*prv,*fwd;
	cur = *h;
	prv = NULL;
	fwd = NULL;
	while(cur != NULL){
		fwd = cur->next;
		cur->next = prv;
		prv = cur;
		cur = fwd;
	}
	*h = prv;
}

int main(void)
{
	struct node *head = NULL;
	create(&head);
	display(head);
	reverse(&head);
	display(head);
}	
