#include <stdio.h>
#include <stdlib.h>

struct node{
	int coeff,exp;
	struct node *next;
};

void create(struct node **h){
	struct node *cur, *ptr;
	*h = NULL;
	for(int i = 0 ;i < 5;++i){
		cur = (struct node *) malloc(sizeof(struct node));
		cur->coeff = random()%11;
		cur->exp = i;
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
	int i = 0;
	for(ptr = h; ptr!= NULL; ptr = ptr->next){
		printf("%dx^%d\t", ptr->coeff,i); i++;
	}
	printf("\n");
}
void multcoeff(struct node **h){
	struct node *ptr;
	int i = 3;
	printf("Multiplying eqn by %d\n",i);
	for(ptr = *h; ptr!= NULL; ptr = ptr->next){
		ptr->coeff = ptr->coeff * i;
	}
}

int main(void){
	struct node *h1,*h2;
	create(&h1); 
	display(h1);
	multcoeff(&h1);
	display(h1);
}
