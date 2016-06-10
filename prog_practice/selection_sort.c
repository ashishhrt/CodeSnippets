//Selection Sort
#include<stdio.h>

void selection_sort(int a[], int size);       //Declaration of selection_sort function

//Driver function
int main(void){
	int a[] = {10,45,32,78,9};
	int i = 0;
	int size = sizeof(a)/sizeof(a[0]);
	selection_sort(a, size);
	printf("Sorted array :\n");
	for( i = 0; i < size; i++ ){
		printf("%d\n",a[i]);
	}
	return 0;
}

//Defination of selection_sort function
void selection_sort(int a[], int size){
	int i = 0;
	int j = 0;
	int swap = 0;
	
	for(i = 0; i < size - 1; i++){
		
		for(j = i+1; j < size; j++){
			if(a[i] > a[j]){
				swap = a[j];
				a[j] = a[i];
				a[i] = swap;
			}
		}
	}
}
