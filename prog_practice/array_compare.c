//WAP if an array contains n elements,check if a[0] == a[n-1], a[1] == a[n-2]

#include<stdio.h>

void array_compare(int a[], int size){
	int i = 0;
	int j = size - 1;
	
	for(i, j; i <= j; j--,i++)
		if(a[i] == a[j])
			printf("equal\n");
}

//Driver function
int main(void){
	const int size = 10;
	int a[10] = {23,343,12,23,43,534,12,98,343,23};
	/*int i = 0;
	for(i = 0; i < size; i++)
		a[i] = i+5;
	*/
	array_compare(a, size);
	
	return 0;
}
