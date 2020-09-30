#include <stdio.h>

struct node
{
    int data;
    struct node* next;
    struct node* prv;
};

void create(struct node **h)
{
    struct node *curr;
    struct node *ptr;
    for(int i=0;i<5;i++)
    {
        curr = (struct node *)malloc(sizeof(struct node));
        curr -> data = rand() % 51;
        curr -> next = NULL;
        curr -> prv = NULL;
        if(*h==NULL)
        {
            *h = curr;
            ptr = curr;
        }
        else
        {
            ptr -> next = curr;
            curr -> prv = ptr;
            ptr = curr;
        }

    }

}

void display(struct node *h)
{
    while(h !=NULL)
    {
        printf("%d\t",h->data);
        h = h -> next;

    }
    printf("\n\n");

}


void insert(struct node **h,int v,int p)
{
    struct node *curr,*ptr;
    curr = (struct node *)malloc(sizeof(struct node));
    curr -> data = v;
    curr ->next = NULL;
    curr ->prv = NULL;
    if(*h == NULL)
        *h = curr;
    else if(p==0)
    {
        curr -> next = *h;
        *h = curr;
        (curr -> next) -> prv = *h;
    }
    else
    {
        ptr = *h;
        int i=1;
        while(i<p && ptr -> next != NULL)
        {
            i++;
            ptr = ptr->next;
        }
        if(ptr->next == NULL)
        {
            ptr -> next = curr;
            curr -> prv = ptr;
        }
        else
        {
            curr -> prv = ptr;
            curr -> next = ptr -> next;
            ptr -> next = curr;
            (curr -> next) -> prv = curr;
        }
    }
}

void del(struct node **h,int p)
{
    struct node *ptr;
    if(*h == NULL)
        printf("No node \n");

    else
    {
        ptr = *h;
        int i=1;
        while(i<p && ptr != NULL)
        {
            i++;
            ptr = ptr-> next;
        }

        if(ptr == NULL)
        {
            printf("Not founf \n");
        }
        else if(ptr == *h && ptr->next == NULL)
        {
            *h=NULL;
            free(ptr);

        }
        else if(ptr==*h)
        {
            *h = ptr->next;
            ptr -> prv = NULL;
            free(ptr);

        }
        else if(ptr->next==NULL)
        {
            (ptr-> prv)-> next = NULL;
            free(ptr);

        }
        else
        {
            (ptr->prv)->next = ptr-> prv;
            (ptr->next)->prv = ptr->prv;

        }





    }


}






int main()
{
    int pos = 2;
    struct node *head = NULL;
    create(&head);
    display(head);
    insert(&head,100,pos);
    display(head);
    del(&head,1);
    display(head);

    return 0;
}
