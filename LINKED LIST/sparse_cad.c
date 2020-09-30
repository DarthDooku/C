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

int main(void)
{
	struct node *h1 = NULL;
	create(&h1);
	display(h1);
}


