#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct data{
	int item;
	int priority;
	int order;
};

struct pque{
	struct data d[MAX];
	int front;
	int rear;
};
int emptyFlag = 1;

void add(struct pque *q, struct data d);
void insertion_sort(struct pque *q);
struct data del(struct pque *);
void shift(struct pque *);

//Driver function
int main(void){
	struct pque q;
	q.front = -1;
	q.rear = -1;
	struct data d;
	int i = 0;


	for(i = 0; i < MAX; i++){
		printf("\n\nEnter data: ");
		scanf("%d",&(d.item));
		printf("\nPriority: ");
		scanf("%d",&(d.priority));
		printf("\nOrdering: ");
		scanf("%d",&(d.order));
		add(&q, d);
	}

	printf("\n\nProcessed data: \n");
	for(i = 0; i < MAX; i++){
		d = del(&q);

		printf("\nData = %d\nPriority = %d\nOrder = %d\n",d.item, d.priority, d.order);
	}

	return 0;
}

void add(struct pque *q, struct data d){
	if(emptyFlag){
		q->front++;
		q->rear++;
		q->d[q->rear] = d;
		emptyFlag = 0;
		return;
	}
	else{
		if(q->front != 0)
			shift(q);
		if(q->rear < (MAX-1)){
			q->rear++;
			q->d[q->rear] = d;
			insertion_sort(q);
			return;
		}
		else{
			printf("\nPriority que is full!\n");
			return;
		}
	}
}

void insertion_sort(struct pque *q){
	int i = 0;
	struct data temp;
	for(i = 0; i < q->rear; i++){
		if((q->d[i]).priority < (q->d[q->rear]).priority){
			temp = q->d[i];
			q->d[i] = q->d[q->rear];
			q->d[q->rear] = temp;
		}
	}
	
}

void shift(struct pque *q){
	int i = 0, j = 0, k = 0;

	i = q->front;
	j = q->rear;

	for(k = 0; k <= (j-i); k++){
		q->d[k] = q->d[i+k];
	}
	q->front = 0;
	q->rear = (q->rear - i);

	return;
}

struct data del(struct pque *q){
	struct data temp;
	if(!emptyFlag){
		temp = q->d[q->rear];
		q->rear -= 1;
		if(q->rear == -1){
			q->front = -1;
			emptyFlag = 1;
		}

		return temp;
	}
	else{
		temp.item = NULL;
		temp.priority = NULL;
		temp.order = NULL;
		printf("\nQueue Empty!\n");
		return temp;
	}

}