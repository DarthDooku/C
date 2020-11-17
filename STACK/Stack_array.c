//Stack operations using array
#include<stdio.h>
#define MAX 5
typedef struct{
    int data[MAX];
    int top;
}STACK;

int push(STACK *s,int v)
{
    if(s->top==MAX-1)
        return 1;
    s->top++;
    s->data[s->top]=v;
    return 0;
}
int pop(STACK *s,int *v) //pop function
{
    if(s->top==-1)
        return 1;
    *v=s->data[s->top];
    s->top--;
    return *v;
}
void traverse(STACK *s)
{
    if(s->top==-1)
        printf("Stack is empty\n");
    else{
        int i;
    printf("Stack elements are:\n");
    for(i=0;i<=(s->top);i++)
    {
        printf("%d\n",s->data[i]);
    }

    }
}
int main()
{
    STACK s1;
    s1.top=-1;
    int ch,v,m,q,k;
    while(1)
    {
        printf("1.Push\n");
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
                    printf("Popped item is %d\n",q);
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
