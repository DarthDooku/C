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

void displayReverse(struct node *h){
	struct node *ptr;
	for(ptr = h; ptr->next != NULL; ptr = ptr->next);
	for( ; ptr != NULL; ptr = ptr->prv){
		printf("%d ", ptr->data);
	}
	printf("\n");
}

void insert(struct node **h, int v, int p){
	struct node *cur,*ptr;
	cur = (struct node *) malloc(sizeof(struct node));
	cur->data = v;
	cur->next = NULL;
	cur->prv = NULL;
	if(*h == NULL){
		*h = cur;
	}
	else if(p == 0){
		cur -> next = *h;
		(*h)->prv = cur;
		*h = cur;
	}
	else{
		ptr = *h; 
		int i = 1;
		while(i<p && ptr -> next != NULL)
		{
			ptr = ptr -> next;
			i++;
		}
		if(ptr -> next == NULL){
			ptr -> next = cur;
			cur -> prv = ptr;	
		}
		else{
			cur->prv = ptr;
			cur->next = ptr->next;
			ptr->next = cur;
			cur->next->prv = cur;
		}
	}
}

void delete(struct node **h, int p){
	struct node *ptr;
	if(*h == NULL){
		printf("Empty\n");
	}
	else{
		ptr = *h; 
		int i = 1;
		while(i < p && ptr != NULL ){
			ptr = ptr -> next;
			i++;
		}
		if(ptr == NULL){
			printf("Not Found\n");
		}
		else if(p == 1){
			*h = ptr -> next;
			(*h)->prv = NULL;
			free(ptr);
		}
		else if(ptr == *h && ptr->next == NULL) free(ptr);
		else if(ptr->next == NULL){
			ptr->prv->next = NULL;
			free(ptr);
		}
		else{
			ptr -> prv -> next = ptr -> next;
			ptr -> next -> prv = ptr -> prv;
			free(ptr);
		}
	}
}

int main(void)
{
	head = NULL;
	create(&head);
	display(head);
	displayReverse(head);
	insert(&head,13,6); display(head);
	insert(&head,13,0); display(head);
	insert(&head,13,3); display(head);
	delete(&head,1); display(head);
	delete(&head,3); display(head);
	delete(&head,8); display(head);
}








