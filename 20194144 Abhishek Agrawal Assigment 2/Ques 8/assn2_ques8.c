/*Abhishek Agrawal
  20194144
  Program to implement a header based circular Doubly Linked List*/
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
	p->next = head->next;
	head->next->prev = p;
	head->next = p;
	p->prev = head;
	printf("Node with data %d is inserted successfully.",x);
	head->data +=1;
}
//2.function to insert at the end
void insert_end(int x)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	if(head->next==head)
	{
		insert_start(x);
		return;
	}
	p->next = head;
	head->prev->next = p;
	p->prev = head->prev;
	head->prev = p;
	printf("Node with data value %d is successfully inserted.",x);
	head->data +=1;	
}
//3.function to insert a node after a particular node
void insert_node_after(int x,int y)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	if(head->next==head)
	{
		printf("list is empty. Can't find the node with the key value after which the node is to be inserted.'");
		return;
	}
	NODE *q = head;
	do
	{
		q = q->next;
	}while(q!=head && q->data!=y);
	if(q==head)
	{
		printf("Node with the given key value doesn't exist.");
		return;
	}
	
	p->next = q->next;
	q->next->prev = p;
	p->prev = q;
	q->next = p;
	printf("Node with data %d is inserted successfully after node with data %d.",x,y);
	head->data +=1;
}
//4.function to insert the node before a particular node
void insert_node_before(int x,int y)
{
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = x;
	if(head->next==head)//list is empty
	{
		printf("list is empty. Can't find the node with the key value after which the node is to be inserted.'");
		return;
	}
	NODE *q = head;
	do
	{
		q = q->next;
	}while(q!=head && q->data!=y);
	if(q==head)
	{
		printf("Node with the given key value doesn't exist.");
		return;
	}
	p->next = q;
	q->prev->next= p;
	p->prev = q->prev; 
	q->prev = p;
	printf("Node with data %d is inserted successfully after node with data %d.",x,y);
	head->data +=1;
}
//5.function to delete a node from the beginnig of the list
void delete_start()
{
	if(head->next==head)
	{
		printf("List is empty. Can't delete anything.");
		return;
	}
	NODE*temp = head->next;
	head->next->next->prev = head;
	head->next = head->next->next;
	printf("Node with data %d is successfullt deleted.",temp->data);
	head->data -=1;
	free(temp);
}//6.function to delete a node at the end of the list
void delete_end()
{
	NODE *q = head;
	if(head->next==head)
	{
		printf("List is empty. Can't delete anything.");
		return;
	}
	NODE *temp = head->prev;
	head->prev->prev->next = head;
	head->prev = head->prev->prev;
	printf("Node with data %d is successfully deleted.",temp->data);
	head->data -= 1;
	free(temp);
}
//7.function to delete a given node
void delete_given_node(int x)
{
	NODE *q = head;
	if(head->next==head)
	{
		printf("List is empty. Can't delete anything.");
		return;
	}
	do
	{
		q = q->next;
	}while(q!=head&&q->data!=x);
	if(q==head) {
		printf("Node with given key value %d is not found.",x);
		return;
	}
	q->prev->next = q->next;
	q->next->prev = q->prev;
	free(q);
	printf("Node with data value %d is successfully deleted.",x);
	head->data-=1;
}
//8.function to display the contents of the list
void display()
{
	if(head->next==head)
	{
		printf("List is empty.");
		return;
	}
	NODE *q = head->next;
	while(q!=head)
	{
		printf("%d -> ",q->data);
		q = q->next;
	}
}
void create_list()
{
	NODE* header = (NODE*)malloc(sizeof(NODE));
	header->data = 0;
	head = header;
	header->next = head;
	header->prev = head;
}
int main()
{
	create_list();
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
	printf("9. Current no of elements in the list:\n");
	printf("10. Exit.");
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
			printf("Current no of elements in the list is %d",head->data);
			break;
		case 10:
			exit(0);
		default:
			printf("Invalid choice.");
	}
}
}

