//WAP that takes 25 numbers as input and find how many of them are negetive, positive, even, odd

#include<stdio.h>

void even_odd_pstive_neg(int num[], int a[]){
	int i = 0;
	
	for(i = 0; i < 25; i++){
		if(num[i] % 2 == 0)
			a[0] += 1;
		else{
			a[1] += 1;
		}
		if(num[i] < 0)
			a[3] += 1;
		else
			a[2] += 1;
	}
}

//Driver function
int main(void){
	int num[25];
	int a[4] = {0,0,0,0};
	int i = 0;
	
	printf("Enter 25 numbers:\n");
	for(i = 0; i < 25; i++)
		scanf("%d",&num[i]);
	
	even_odd_pstive_neg(num, a);
	
	printf("Number of:\n");
	printf("\tEven numbers: %d\n",a[0]);
	printf("\tOdd numbers: %d\n",a[1]);
	printf("\tPositive numbers: %d\n",a[2]);
	printf("\tNegetive numbers: %d\n",a[3]);
	
	return 0;
}
