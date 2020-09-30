#include <stdio.h>
#include <stdlib.h>

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
			cur->next = *h;
		}
		else{
			ptr->next = cur;
			ptr = cur;
			cur->next = *h;
		}
	}
}

void display(struct node *h){
	struct node *ptr = h;
	do{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}while(ptr != h);
	printf("\n");
} 
void insert(struct node **h, int v, int p){
	struct node *cur,*ptr;
	cur = (struct node *)malloc(sizeof(struct node));
	cur->data = v;
	cur->next = NULL;
	if(*h == NULL){
		*h = cur;
		cur->next = *h;
	}
	else if(p == 0){
		for(ptr = *h; ptr->next != *h; ptr=ptr->next);
		cur->next = *h;
		ptr->next = cur;
		*h = cur;
	}
	else{
		ptr = *h;
		int i = 1;
		while(i<p){
			ptr = ptr->next;
			i++;
		}
		cur->next = ptr->next;
		ptr->next = cur;
	}
}
void delete(struct node **h, int p){
	struct node *ptr,*prv;
	if(*h == NULL){
		printf("Empty\n");
	}
	else{
		ptr = *h; 
		int i = 1;
		while(i < p && ptr->next != *h )
		{
			prv = ptr;
			ptr = ptr -> next;
			i++;
		}
		if(ptr->next == *h && i<p){
			printf("Not Found\n");
		}
		else if(ptr == *h && ptr->next == ptr){
			*h = NULL;
			free(ptr);
		}
		else if(ptr == *h){
			struct node *tmp;
			for(tmp = *h; tmp->next != *h; tmp=tmp->next);
			tmp->next = (*h)->next;
			*h = (*h)->next;
			free(ptr);
		}
		else{
			prv -> next = ptr -> next;
			free(ptr);
		}
	}
}
int main(void)
{
	struct node *head = NULL;
	create(&head);
	display(head);
	insert(&head,13,6); display(head);
	insert(&head,13,0); display(head);
	insert(&head,13,3); display(head);
	delete(&head,1); display(head);
	delete(&head,3); display(head);
	delete(&head,8); display(head);
}
