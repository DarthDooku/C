#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next,*prv;
}*head;

void create(struct node **h){
	struct node *cur, *ptr;
	for(int i = 0 ;i < 5;++i){
		cur = (struct node *)malloc(sizeof(struct node));
		cur->data = random()%11;
		cur->next = NULL;
		cur->prv = NULL;
		if(*h == NULL){
			*h = cur;
			ptr = cur;
		}
		else{
			cur->prv = ptr;
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
	if(*h == NULL || (*h)->next == NULL){
		printf("Invalid\n");
		return;
	}
	struct node *tmp,*ptr;
	tmp = NULL;
	ptr = *h;
	while(ptr != NULL){
		 tmp = ptr->prv;
		 ptr->prv = ptr->next;
		 ptr->next = tmp;
		 ptr = ptr->prv;
	}
	*h = tmp->prv;
}

int main(void)
{
	struct node *head = NULL;
	create(&head);
	display(head);
	reverse(&head);
	display(head);
}

