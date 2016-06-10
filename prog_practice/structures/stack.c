//WAP to impliment stack using linked list
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

struct node *base = NULL, *top = NULL, *current = NULL, *newNode = NULL;

void clear(){
	while(getchar() != '\n');
}

void menu(){
	system("clear");
	printf("Options:\n\n");
	printf("1.Push element\n2.Pop element\n3.Search element\n4.Display elements\n5.Exit\n");
}

//push()
void push();
//pop()
void pop();
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
				push();
				break;
			case 2:
				pop();
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

//defination of push()
void push(){
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
			newNode->ptr = top;

			if(base == NULL){
				base = newNode;
				top = base;
				newNode = NULL;
			}
			else{
				top = newNode;
				newNode = NULL;
			}
			printf("%d successfully pused into the stack!\n",data);
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

//defination of pop()
void pop(){
	char ch;
	int data;
	while(TRUE){
		system("clear");
		if(top == NULL && base == NULL){
			printf("Stack empty!\n");
			printf("\nPress Enter to continue...");
			clear();
			getchar();
			break;	
		}
		else{
			if(top -> ptr == NULL){     //Empty the stack
				data = top->data;
				free(top);
				top = NULL;
				base = top;
			}
			else{
				data = top->data;
				current = top;
				top = top -> ptr; // moving top pointer down
				free(current);
				current = NULL;
			}
			printf("%d successfully poped out of the stack!\n",data);
			printf("\nWould like to pop another element?(y/n):\t");
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
	if(top == NULL){
		printf("Stack is Empty!\n");
		printf("\nPress Enter to continue...");
		clear();
		getchar();
	}
	else{
		current = top;
		printf("Elements in the stack are:\n");
		while(current != NULL){
			printf("%d\n",current->data);
			current = current->ptr;
		}
		printf("\nPress Enter to continue...");
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
		if(top == NULL){
			printf("Stack is Empty!\n");
			printf("\nPress Enter to continue...");
			clear();
			getchar();
			break;
		}
		else{
			printf("Enter the element to search:\t");
			scanf("%d",&data);
			current = top;
			status = 0;
			while(current != NULL){
				i++;
				if(current->data == data){
					status = 1;
					break;
				}
				current = current->ptr;
			}
			if(status == 1){
				printf("%d is present at the %d position from top in the stack!\n",data,i);
			}
			else{
				printf("%d is NOT in the stack!\n",data);
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