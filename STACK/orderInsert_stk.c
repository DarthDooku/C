#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct{
    int data[max];
    int top;
}STACK;

void display(STACK *s)
{
    int t=s->top;
    while(t!=-1)
    {
        printf("%d ",s->data[t--]);
    }
    printf("\n");
}


int push(STACK *s, int v)
{
    if(s->top==max-1)
    {
        printf("Stack Overflow");
        return 1;
    }
    s->top++;
    s->data[s->top]=v;
    return 0;
}

int pop(STACK *s, int *v)
{
    if(s->top==-1)
    {
        printf("Stack Underflow");
        return 1;
    }
    *v=s->data[s->top];
    s->top--;
    return 0;
}

void orderInsert(STACK *s)
{
    int a[]={5,2,3,5,8,2,33,4,7,4,9,1};
    STACK temp;
    temp.top=-1;
    for(int i=0; i<12; i++)
    {
        if(s->top==-1 || s->data[s->top]>=a[i])
        push(s,a[i]);
        else{
            while(s->data[s->top]<a[i] && s->top!=-1)
            {
                int m;
                pop(s,&m);
                push(&temp,m); 
            }
            push(s,a[i]);
            while(temp.top!=-1)
            {
                int m;
                pop(&temp,&m);
                push(s,m);
            }   
        }
    }
}
int main()
{
    int m,k,q;
    STACK s1;
    s1.top=-1;
    orderInsert(&s1);
    display(&s1);
return 0;
}