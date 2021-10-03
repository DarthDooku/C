#include<stdio.h>
#define MAX 10
typedef struct
{
    int data[MAX];
    int top;
}STACK;

int pushStack(STACK *s1, int v)
{
    if(s1->top == MAX-1)
    {
        printf("Overflow\n");
        return 1;
    }
    (s1->top)++;
    s1->data[s1->top] = v;
    return 0;

}

int popStack(STACK *s, int *v)
{
    if(s->top==-1)
    {
        printf("Underflow\n");
        return 1;
    }
    *v = s->data[s->top];
    s->top--;
    return 0;
}

int copyStack(STACK s1, STACK *s2)
{
    for(int i=0;i<=s1.top;i++)
    {
        if(s2->top==MAX-1)
        {
            printf("Overflow\n");
            return 1;
        }
        s2->top++;
        s2->data[s2->top] = s1.data[s2->top];
    }
    return 0;
}


int main()
{
    int m,k,q;
    STACK s1,s2;
    s1.top = -1;
    s2.top = -1;
    k = pushStack(&s1,5);
    k = pushStack(&s1,10);
    k = pushStack(&s1,15);
    k = pushStack(&s1,20);

    for(int i=0;i<=s1.top;i++)
        printf("%d\t",s1.data[i]);
    printf("\n");

    copyStack(s1,&s2);

    for(int i=0;i<=s1.top;i++)
        printf("%d\t",s2.data[i]);
    printf("\n");

    q = popStack(&s1,&m);
    q = popStack(&s1,&m);
    q = popStack(&s1,&m);

    for(int i=0;i<=s1.top;i++)
        printf("%d\t",s1.data[i]);

    return 0;
}
