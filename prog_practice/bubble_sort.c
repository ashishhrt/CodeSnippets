//Bubble sort

#include<stdio.h>

void bubble_sort(int a[], int size);        //Declaration of bubble_sort function

//Driver function
int main(void){
	int a[] = {45,854,12,92,49};
	int size = sizeof(a)/sizeof(a[0]);
	int i = 0;
	
	printf("Bubble sort\n\nSorted array:\n");
	bubble_sort(a, size);
	
	for(i = 0; i < size; i++){
		printf("%d\n",a[i]);
	}
	
	return 0;
}

//Defination of bubble_sort function
void bubble_sort(int a[], int size){
	int i = 0;
	int j = 0;
	int k = 0;
	int swap = 0;
	
	for(i = 0; i < size - 1; i++){
		k = 0;
		for(j = 1; j < size; j++){
			if(a[k] > a[j]){
				swap = a[j];
				a[j] = a[k];
				a[k] = swap;
			}
			k += 1;
		}
	}
}
