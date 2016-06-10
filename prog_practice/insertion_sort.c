//Insertion Sort

#include<stdio.h>

void insertion_sort(int a[], int size);            //Declaration of insertion_sort function

//Driver function
int main(void){
	int i = 0;
	int a[] = {52,632,82,21,92};
	int size = sizeof(a)/sizeof(a[0]);
	
	printf("Insertion Sort:\n\nSorted array:\n");
	insertion_sort(a, size);
	
	for(i = 0; i < size; i++){
		printf("%d\n",a[i]);
	}
	
	return 0;
}

//Defination of insertion_sort function
void insertion_sort(int a[], int size){
	int i = 0;
	int j = 0;
	int k = 0;
	int swap = 0;
	
	for(i = 1; i < size; i++){
		k = i;
		for(j = i-1; j > -1; j--){
			if(a[k] < a[j]){
				swap = a[j];
				a[j] = a[k];
				a[k] = swap;
				k -= 1;
			}
			else
				break;
		}
	}
}
