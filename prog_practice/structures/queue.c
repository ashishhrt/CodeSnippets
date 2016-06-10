//WAP to impliment queue data structure using linked list
/*
*Developed by Ashish Kumar on 2/7/2015
*/
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

struct node{
	int data;
	struct node *ptr;
};

struct node *front = NULL, *rear = NULL, *current = NULL, *newNode = NULL;

void clear(){
	while(getchar() != '\n');
}

void menu(){
	system("clear");
	printf("Options:\n\n");
	printf("1.Add element\n2.Delete element\n3.Search element\n4.Display elements\n5.Exit\n");
}

//push()
void add();
//pop()
void delete();
//search()
void search();
//display()
void display();

//Driver function
int main(void){
	int ch;

	while(TRUE){
		menu();
		printf("\nEnter your Choice:\t");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				add();
				break;
			case 2:
				delete();
				break;
			case 3:
				search();
				break;
			case 4:
				display();
				break;
			default:
				ch = 0;
				break;
		}

		if(ch == 0)
			break;
	}

	printf("\nThanks for using...");
	clear();
	getchar();
	system("clear");

	return 0;
}

//defination of add()
void add(){
	char ch;
	int data;

	while(TRUE){
		system("clear");
		newNode = (struct node *)malloc(sizeof(struct node));
		if(newNode == NULL){
			printf("Memory full!\n");
			printf("\nPress Enter to continue...");
			clear();
			getchar();
			break;
		}
		else{
			printf("Enter data:\t");
			scanf("%d",&data);
			newNode->data = data;
			newNode->ptr = NULL;

			if(front == NULL){
				front = newNode;
				rear = front;
				newNode = NULL;
			}
			else{
				rear->ptr = newNode;
				rear = newNode;
				newNode = NULL;
			}
			printf("%d successfully added into the queue!\n",data);
			printf("\nWould like to add new element?(y/n):\t");
			clear();
			ch = getchar();
			if('y' == ch || 'Y' == ch)
				continue;
			else
				break;
		}
	}
}
//defination of delete()
void delete(){
	char ch;
	int data;
	while(TRUE){
		system("clear");
		if(front == NULL && rear == NULL){
			printf("Queue empty!\n");
			printf("\nPress Enter to continue...");
			clear();
			getchar();
			break;	
		}
		else{
			if(front->ptr == NULL){     //Empty the queue
				data = front->data;
				free(front);
				front = NULL;
				rear = front;
			}
			else{
				data = front->data;
				current = front;
				front = front -> ptr; // moving rear pointer down
				free(current);
				current = NULL;
			}
			printf("%d successfully deleted out of the queue!\n",data);
			printf("\nWould like to delete another element?(y/n):\t");
			clear();
			ch = getchar();
			if('y' == ch || 'Y' == ch)
				continue;
			else
				break;
		}
	}
}

//defination of display()
void display(){
	system("clear");
	if(front == NULL){
		printf("Queue is Empty!\n");
		printf("\nPress Enter to continue...");
		clear();
		getchar();
	}
	else{
		current = front;
		printf("Elements in the queue are:\n");
		while(current != NULL){
			printf("%d\t",current->data);
			current = current->ptr;
		}
		printf("\n\nPress Enter to continue...");
		clear();
		getchar();
	}
}

//defination of search()
void search(){
	int data, i = 0,status;
	char ch;

	while(TRUE){
		system("clear");
		i = 0;
		if(front == NULL){
			printf("Queue is Empty!\n");
			printf("\nPress Enter to continue...");
			clear();
			getchar();
			break;
		}
		else{
			printf("Enter the element to search:\t");
			scanf("%d",&data);
			current = front;
			status = 0;
			while(current != NULL){
				i++;
				if(current->data == data){
					status = 1;
					break;
				}
				current = current->ptr;
			}
			current = NULL;
			if(status == 1){
				printf("%d is present at the %d position from front in the queue!\n",data,i);
			}
			else{
				printf("%d is NOT in the queue!\n",data);
			}
			printf("\nWould like to search another element?(y/n):\t");
			clear();
			ch = getchar();
			if('y' == ch || 'Y' == ch)
				continue;
			else
				break;
		}
	}
}