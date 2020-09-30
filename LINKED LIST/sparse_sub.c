
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int r;
	int c;
	int v;
	struct node *next;
};

void create(struct node **);
void display(struct node *);
void add(struct node  *,struct node *,struct node **);

int main()
{
	int i;
	struct node *h1,*h2,*h3;
	h1=h2=h3=NULL;
	create(&h1);
	create(&h2);
	
	printf("_____________________\n");
	printf("Sparse Matrix1\n");
	display(h1);
	printf("Sparse Matrix2\n");
	display(h2);
	
	//making the values of h2 negative
	struct node *p;
	p=h2->next;
	for(i=0;i<h2->v;i++)
	{
		p->v*=-1;
		p=p->next;
	}
		
	printf("_____________________\n");
	add(h1,h2,&h3);
	if(h3!=NULL)
	{
		printf("Matrix1+Matrix2\n");
		display(h3);
	}
	else
		printf("Can't add\n");
}

void create(struct node **h)
{
	*h=(struct node*)malloc(sizeof(struct node));
	printf("Enter no. of rows & no. of columns & no. of non zero elements\n");
	scanf("%d%d%d",&(*h)->r,&(*h)->c,&(*h)->v);
	(*h)->next=NULL;
	
	int i;
	struct node *cur,*p=*h;
	for(i=0;i<(*h)->v;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("Enter row no. & column no. & non zero element\n");
		scanf("%d%d%d",&cur->r,&cur->c,&cur->v);
		cur->next=NULL;
		
		p->next=cur;
		p=cur;
	}
}	

void display(struct node *h)
{
	int i,j,t=0;
	struct node *p;
	for(i=0;i<h->r;i++)
	{
		for(j=0;j<h->c;j++)
		{
			p=h->next;
			while(p!=NULL)
			{
				if(p->r==i&&p->c==j)
				{
					printf("%d  ",p->v);
					t=1;
				}
				p=p->next;
			}
			if(t==0)
				printf("0  ");
			else
				t=0;
		}
		printf("\n");
	}
}

void add(struct node *h1,struct node *h2,struct node **h)
{
	if(!((h1->r==h2->r)&&(h1->c==h2->c)))
		return;
	
	struct node *prv,*p,*cur,*p1,*p2;
	*h=(struct node *)malloc(sizeof(struct node));
	(*h)->r=h1->r;
	(*h)->c=h1->c;
	(*h)->v=h1->v+h2->v;
	(*h)->next=NULL;
	prv=*h;
	
	for(p=h1;p!=NULL;p=p->next)
	{
		cur=(struct node *)malloc(sizeof(struct node));
		cur->r=p->r;
		cur->c=p->c;
		cur->v=p->v;
		cur->next=NULL;
		prv->next=cur;
		prv=cur;
	}
	for(p=h2;p!=NULL;p=p->next)
	{
		cur=(struct node *)malloc(sizeof(struct node));
		cur->r=p->r;
		cur->c=p->c;
		cur->v=p->v;
		cur->next=NULL;
		prv->next=cur;
		prv=cur;
	}
	
	for(p1=(*h)->next;p1!=NULL;p1=p1->next)
	{
		prv=p1;
		p2=p1->next;
		while(p2!=NULL)
		{
			if(p1->r==p2->r&&p1->c==p2->c)
			{
				p1->v+=p2->v;
				prv->next=p2->next;
				free(p2);
				p2=prv;
				(*h)->v--;
			}
			prv=p2;
			p2=p2->next;
			
		}
	}
}
