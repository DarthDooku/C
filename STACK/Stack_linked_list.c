#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct
{
    struct node * top;
}STACK;

int push(STACK *s,int v)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        //printf("Overflow");
        return 1;
    }
    temp->data=v;
    temp->next=s->top;
    s->top=temp;
    return 0;
}
int pop(STACK *s,struct node **v)
{
    struct node *temp;
    if(s->top==NULL)
    {
        //printf("Underflow");
        return 1;
    }
    temp=s->top;
    s->top=temp->next;
    *v=temp;
    return 0;
}
void traverse(STACK *s)
{
    if(s->top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *temp;
        printf("Stack elements are:\n");
        for(temp=s->top;temp!=NULL;temp=temp->next)
        {
            printf("%d",temp->data);
        }
    }
}
int main()
{
    struct node *m;
    STACK s1;
    s1.top = NULL;
    int ch,v,q,k;
    while(1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Traverse\n");
        printf("4.Quit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&v);
                k=push(&s1,v);
                if(k==1)
                  printf("Stack Overflow\n");
                else
                  printf("%d pushed\n",v);
                break;
            case 2:
                q=pop(&s1,&m);
                if(q==1)
                    printf("Stack is underflow\n");
                else
                    printf("Popped item is %d\n",m->data);
                break;
            case 3:
                traverse(&s1);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
