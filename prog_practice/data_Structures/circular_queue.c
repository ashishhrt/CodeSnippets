//WAP to implement circular queue using array
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define EMPTY 1

int emptyFlag = EMPTY;
int index_(int Index);
void insert(int q[],int data, int *rear, int *front);
void delete(int q[],int *front, int* rear);

//Driver function
int main(void){
	int queue[MAX];
	int front, rear;
	//Initialize
	front = -1;     
	rear = -1;

	insert(queue,5, &rear, &front);
	insert(queue,7, &rear, &front);
	insert(queue,8, &rear, &front);
	insert(queue,22, &rear, &front);
	insert(queue,12, &rear, &front);
	insert(queue,9, &rear, &front);

	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);

	insert(queue,15, &rear, &front);
	insert(queue,45, &rear, &front);
	insert(queue,67, &rear, &front);
	insert(queue,60, &rear, &front);
	insert(queue,31, &rear, &front);
	insert(queue,59, &rear, &front);
	insert(queue,94, &rear, &front);
	insert(queue,56, &rear, &front);
	insert(queue,37, &rear, &front);

	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);
	delete(queue,&front, &rear);

	printf("\nfront = %d\t rear = %d\n",front, rear);
	return 0;

}

int index_(int Index){
	return (Index + 1)%MAX;
}

void insert(int q[],int data, int *rear, int *front){
	int x;
	x = index_(*rear);
	if(x == *front){
		printf("\nQueue Overflow!\n");
		return;
	}

	q[x] = data;
	if((*rear = *front) && emptyFlag){
		*front = *rear = x;
	}
	else{
		*rear = x;
	}
	printf("\n%d inserted!",data);
	emptyFlag = 0;
	return;
}

void delete(int q[], int *front, int *rear){
	int x = 0;
	if(emptyFlag){
		printf("\nQueue Empty!\n");
		return;
	}

	x = index_(*front);
	if(*front != *rear){
		printf("\nDeleted Element: %d\n", q[*front]);
		*front = x;
	}
	else if(*front == *rear){
		printf("\nDeleted Element: %d\n", q[*front]);
		emptyFlag = EMPTY;

	}

}