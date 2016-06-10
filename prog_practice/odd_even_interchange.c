//WAP that interchanges the odd and even elements of an array.

#include<stdio.h>

void odd_even_interchange(int a[],int size){
	int i = 0;
	int j = 0;
	int k = 0;
	int swap = 0;
	
	for(i = 0; i < size - 1; i++){
		if(a[i] % 2 == 0){
			for(j = k; j < size; j++){
				if(a[j] % 2 != 0){
					swap = a[j];
					a[j] = a[i];
					a[i] = swap;
					k = j;
					break;
				}
			}
		}
	}
}

//Driver function
int main(){
	int a[10] = {24,64,49,25,90,57,36,23,29,10};
	int i = 0;
	int size = sizeof(a)/sizeof(a[0]);
	
	printf("Elements of array:\n");
	for(i = 0; i < size; i++)
		printf("%d\t",a[i]);
	
	odd_even_interchange(a, size);
	
	printf("\nElements after odd - even interchange:\n");
	for(i = 0; i < size; i++)
		printf("%d\t",a[i]);
	
	printf("\n");
	return 0;
}
