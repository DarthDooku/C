#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
typedef struct node NODE;
NODE *head = NULL;
//1.insert node at the beginning
void insert_start(int x)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	p->next = head;
	head = p;
	printf("Node inserted");
}
//2.insert at the end
void insert_end(int x)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	p->next = NULL;
	NODE *q = head;
	if(head==NULL)//if the node to be added is the first node itself
	{
		head = p;
		printf("Node inserted ");
		return;
	}
	while(q->next!=NULL)
	{
		q = q->next;
	}
	q->next= p;
	printf("Node inserted");
}
//3.insert node after particular node
void insert_after(int x,int y)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	if(head==NULL)
	{
		printf("Underflow");
		return;
	}
	NODE *q = head;
	while(q!=NULL && q->data!=y)
	{
		q = q->next;
	}
	if(q==NULL)
	{
		printf("Node doesn't exist.");
		return;
	}
	p->next = q->next;
	q->next = p;
	printf("Node inserted ");
}
//4.insert the node before particular node
void insert_before(int x,int y)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	if(head==NULL)
	{
		printf("List is empty.");
		return;
	}
	if(head->data==y)
	{
		insert_start(x);
		return;
	}
	NODE *q = head;
	while(q->next->data!=y&&q->next->next!=NULL)
	{
		q = q->next;
	}
	if(q->next->data!=y&&q->next->next==NULL)
	{
		printf("Node doesn't exist");
		return;
	}
	p->next = q->next;
	q->next = p;
	printf("Node inserted");
	
}
//5.delete first node
void delete_start()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	NODE *q = head;
	head = head->next;
	printf("Node deleted.");
	free(q);
}//6.delete last node
void delete_end()
{
	NODE *q = head;
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	if(head->next==NULL)
	{
		NODE *temp = head;
		head = head->next;
		printf("Node deleted ");
		free(temp);
		return;
	}
	while(q->next->next!=NULL)
	{
		q = q->next;
	}
	NODE *temp = q->next;
	q->next = NULL;
	printf("Node deleted.");
	free(temp);
}
//7.delete particular node
void delete_part(int x)
{
	NODE *q = head;
	if(head==NULL)
	{
		printf("List is empty.");
		return;
	}
	if(q->data==x)
	{
		delete_start();
		return;
	}
	while(q->next!=NULL&&q->next->data!=x)
	{
		q= q->next;
	}
	if(q->next==NULL&&q->data==x) 
	{
		delete_end();
		return;
	}
	if(q->next==NULL&&q->data!=x) 
	{
		printf("Node not found.");
		return;
	}
	NODE *temp = q->next;
	q->next = q->next->next;
	printf("Node deleted.");
	free(temp);
}
//8.display the list
void display()
{
	if(head==NULL)
	{
		printf("List is empty.");
		return;
	}
	NODE *q = head;
	while(q!=NULL)
	{
		printf("%d , ",q->data);
		q = q->next;
	}
}
int main()
{
	int choice,x,y;
	while(1){
	printf("\nChoices are : \n");
	printf("1. Insert node at the beginning :\n");
	printf("2. Insert node at the end :\n");
	printf("3. Insert node after a given node :\n");
	printf("4. Insert node before a given node : \n");
	printf("5. Delete a node at the beginning:\n");
	printf("6. Delete a node at the end :\n");
	printf("7. Delete a node with a given value:\n");
	printf("8. Display the list:\n");
	printf("9. Exit:\n");
	printf("\n\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the value to be added :");
			scanf("%d",&x);
			insert_start(x);
			break;
		case 2:
			printf("Enter the value to be added :");
			scanf("%d",&x);
			insert_end(x);
			break;
		case 3:
			printf("Enter the value to be added :");
			scanf("%d",&x);
			printf("Enter the value of the node after which you want to enter the node.");
			scanf("%d",&y);
			insert_after(x,y);
			break;
		case 4:
			printf("Enter the value to be added :");
			scanf("%d",&x);
			printf("Enter the value of the node before which you want to enter the node.");
			scanf("%d",&y);
			insert_before(x,y);
			break;
		case 5:
			delete_start();
			break;
		case 6:
			delete_end();
			break;
		case 7:
			printf("Enter the value of the node to be deleted.");
			scanf("%d",&x);
			delete_part(x);
			break;
		case 8:
			display();
			break;
		case 9:
			exit(0);
		default:
			printf("Invalid choice.");
	}
}
}

