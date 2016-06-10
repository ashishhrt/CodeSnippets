//WAP using pointers to find the smallest element of the array

#include<stdio.h>

int* smallest_element_array(int a[], int size){
	int i = 1;
	int *smallest = &a[0];
	
	for(i; i < size; i++){
		if(a[i] < *smallest)
			smallest = &a[i];
	}
	
	return smallest;
}

//Driver function
int main(void){
	int a[5] = {45,26,74,8,23};
	int size = sizeof(a)/sizeof(a[0]);
	
	printf("smallest element of array = %d\n", *smallest_element_array(a, size));
	
	return 0;
}
