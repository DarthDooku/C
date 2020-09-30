#include <stdio.h>
#include <stdlib.h>

struct node{
	int r,c,v;
	struct node *next;
};

void create(struct node **h){
	struct node *ptr,*cur;
	*h = (struct node *) malloc(sizeof(struct node));
	printf("Enter r,c,v:\n");
	scanf("%d%d%d",&(*h)->r,&(*h)->c,&(*h)->v);
	(*h)->next = NULL;
	ptr = *h;
	for(int i=0; i< (*h)->v; i++){
		cur = (struct node *) malloc(sizeof(struct node));
		cur->r = random()%((*h)->r);
		cur->c = random()%((*h)->c);
		//scanf("%d",&(cur->r));
		//scanf("%d",&(cur->c));
		cur->v = random()%7 + 1;
		cur->next = NULL;
		ptr->next = cur;
		ptr = cur;	
	}
}


void display(struct node *h){
	struct node *ptr;
	printf("r c v\n");
	for(ptr = h; ptr!= NULL; ptr = ptr->next){
		printf("%d %d %d\n", ptr->r,ptr->c,ptr->v);
	}
	printf("\n");
}

void mult(struct node *h1, struct node *h2, struct node **h3){
	struct node *p1,*p2,*cur,*ptr;
	if(h1->c != h2->r){
		printf("Invalid\n");
		return;
	}
	*h3 = (struct node *) malloc(sizeof(struct node));
	(*h3)->r = h1->r;
	(*h3)->c = h2->c;
	(*h3)->v = 0;
	(*h3)->next = NULL;
	ptr = *h3;
	for(p1 = h1->next; p1 != NULL; p1=p1->next){
		for(p2 = h2->next; p2 != NULL; p2=p2->next){
			if(p1->c == p2->r){
				cur = (struct node *) malloc(sizeof(struct node));
				cur->r = p1->r;
				cur->c = p2->c;
				cur->v = p1->v * p2->v;
				cur->next = NULL;
				ptr->next = cur;
				ptr = cur;
				((*h3)->v)++;
			}
		}
	}
}

int main(void)
{
	struct node *h1,*h2,*h3;
	h1 = NULL; h2 = NULL; h3 = NULL;
	create(&h1); create(&h2);
	printf("MATRIX A\n");
	display(h1);
	printf("MATRIX B\n");
	display(h2);
	mult(h1,h2,&h3);
	printf("Resultant AXB\n");
	display(h3);
	
}


