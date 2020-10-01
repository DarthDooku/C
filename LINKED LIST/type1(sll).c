#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void create(struct node **h){			//Create Function
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

void insert(struct node **h,int v, int n){
	struct node *cur,*ptr;
	cur = (struct node *) malloc(sizeof(struct node));
	cur->data = v;
	cur->next = NULL;
	if(*h == NULL){
		*h = cur;
	}
	else if(n == 0){
		cur -> next = *h;
		*h = cur;
	}
	else{
		ptr = *h; 
		int i = 0;
		while(i<n-1 && ptr -> next != NULL)
		{
			ptr = ptr -> next;
			i++;
		}
		cur -> next = ptr -> next;
		ptr -> next = cur;
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
		while(i < p && ptr != NULL )
		{
			prv = ptr;
			ptr = ptr -> next;
			i++;
		}
		if(ptr == NULL){
			printf("Not Found\n");
		}
		else if(p == 1){
			*h = ptr -> next;
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
