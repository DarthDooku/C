#include <stdio.h>
#include <stdlib.h>

struct node{
	int coeff,exp;
	struct node *next;
};

void create(struct node **h, int n){
	struct node *cur, *ptr;
	*h = NULL;
	for(int i = 0 ;i <= n;++i){
		cur = (struct node *) malloc(sizeof(struct node));
		printf("Enter coeff of x^%d : ",i);
		scanf("%d",&(cur->coeff));
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
void join(struct node **h1,struct node *h2){
	struct node *ptr;
	if(*h1 == NULL){
		*h1 = h2;
		return;
	}
	for(ptr = *h1; ptr->next != NULL; ptr = ptr->next);
	ptr->next = h2;
}
void simplify(struct node **h){
	struct node *ptr,*ptr1,*prv;
	for(ptr = *h; ptr!=NULL; ptr=ptr->next){
		prv = ptr;
		ptr1 = ptr->next;
		while(ptr1!=NULL){
			if(ptr->exp == ptr1->exp){
				ptr->coeff = ptr->coeff + ptr1->coeff;
				prv->next = ptr1->next;
				free(ptr1);
				ptr1 = prv;
			}
			prv = ptr1;
			ptr1 = ptr1->next;
		}
	}
}

int main(void){
	struct node *h1,*h2;
	int n;
	printf("Enter max power : ");
	scanf("%d",&n);
	create(&h1,n);
	printf("Enter max power : ");
	scanf("%d",&n); 
	create(&h2,n);
	display(h1); display(h2);
	join(&h1,h2);
	simplify(&h1);
	display(h1);
}
