/*Abhishek Agrawal
20194144
  Program to implement a Doubly Linked List*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
typedef struct node NODE;
NODE *head = NULL;
//1.function to insert node at the beginning  of the list.
void insert_start(int x)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	p->next = head;
	p->prev = NULL;
	head = p;
	printf("Node with data %d is inserted successfully.",x);
}
//2.function to insert at the end
void insert_end(int x)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	p->next = NULL;
	NODE *q = head;
	if(head==NULL){
		head = p;
		p->prev = NULL;
		printf("Node with data %d is inserted successfully.",x);
		return;
	}
	while(q->next!=NULL){
		q = q->next;
	}
	q->next = p;
	p->prev = q;
	printf("Node with data %d is inserted successfully.",x);
}
//3.function to insert a node after a particular node
void insert_node_after(int x,int y)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	if(head==NULL)//list is empty
	{
		printf("list is empty. Can't find the node with the key value after which the node is to be inserted.'");
		return;
	}
	NODE *q = head;
	while(q!=NULL && q->data!=y){
		q = q->next;
	}
	if(q==NULL){
		printf("Node with the given key value doesn't exist.");
		return;
	}
	p->next = q->next;
	if(q->next!=NULL)
	q->next->prev = p;
	p->prev = q;
    q->next = p;
	printf("Node with data %d is inserted successfully after node with data %d.",x,y);
}
//4.function to insert the node before a particular node
void insert_node_before(int x,int y)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	if(head==NULL)
	{
		printf("list is empty. Can't find the node with the key value");
		return;
	}
	if(head->data==y)
	{
		insert_start(x);
		return;
	}
	NODE *q = head;
	while(q!=NULL && q->data!=y)
	{
		q = q->next;
	}
	if(q==NULL)
	{
		printf("Node with the given key value doesn't exist.");
		return;
	}
	p->next = q;
	q->prev->next= p;
	p->prev = q->prev; 
	q->prev = p;
	printf("Node with data %d is inserted successfully after node with data %d.",x,y);
}
//5.function to delete a node from the beginnig of the list
void delete_start()
{
	if(head==NULL)
	{
		printf("List is empty. Can't delete anything.");
		return;
	}
	NODE *q = head;
	head = head->next;
	if(head!=NULL)
	head->prev = NULL;
	printf("Node with data value %d is successfully deleted.",q->data);
	free(q);
}//6.function to delete a node at the end of the list
void delete_end()
{
	NODE *q = head;
	if(head==NULL)
	{
		printf("List is empty. Can't delete anything.");
		return;
	}
	if(head->next==NULL)
	{
		printf("Node with value %d is successfully deleted from the list.",head->data);
		free(head);
		return;
	}
	while(q->next!=NULL)
	{
		q = q->next;
	}
	q->prev->next = NULL;
	printf("Node with data value %d is successfully deleted.",q->data);
	free(q);
}
//7.function to delete a given node
void delete_given_node(int x)
{
	NODE *q = head;
	if(q==NULL)
	{
		printf("List is empty. Can't delete anything.");
		return;
	}
	if(q->data==x){
		head = head->next;
		printf("Node with value %d is successfully deleted.",x);
		free(q);
		return;
	}
	while(q!=NULL&&q->data!=x)
	{
		q = q->next;
	}
	if(q==NULL) {
		printf("Node with given key value %d is not found.",x);
		return;
	}
	q->prev->next = q->next;
	if(q->next!=NULL)
	q->next->prev = q->prev;
	free(q);
	printf("Node with data value %d is successfully deleted.",x);
}
//8.function to display the contents of the list
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
		printf("%d -> ",q->data);
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
			insert_node_after(x,y);
			break;
		case 4:
			printf("Enter the value to be added :");
			scanf("%d",&x);
			printf("Enter the value of the node before which you want to enter the node.");
			scanf("%d",&y);
			insert_node_before(x,y);
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
			delete_given_node(x);
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

