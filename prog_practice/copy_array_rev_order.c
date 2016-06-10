//WAP to copy elements of one array into other in reverse order

#include<stdio.h>

void copy_array_rev_order(int a[],int b[],int size);     //Declarstion of copy_array_rev_order functon

//Driver function
int main(void){
	int a[5] = {4,7,23,77,34};
	int size = sizeof(a)/sizeof(a[0]);
	int b[size];
	int i = 0;
	
	copy_array_rev_order(a, b, size);
	
	printf("Elements of first array:\n");

	for(i = 0; i < size; i++)
		printf("%d\n",a[i]);
	
	printf("Elements of second array:\n");

	for(i = 0; i < size; i++)
		printf("%d\n",b[i]);
		
	return 0;
}

//Defination of copy_array_rev_order

void copy_array_rev_order(int a[], int b[], int size){
	int i = 0;
	int j = size - 1;
	
	for(i = 0, j = size -1; j > -1; j--, i++){
		b[i] = a[j];
	}
}
