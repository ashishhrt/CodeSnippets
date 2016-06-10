//WAP to find the largest number if the 5*5 matrix

#include<stdio.h>

int findLargest(int (*array)[5], int rows);              //Declaration of findLargest function

//Driver function
int main(void){
	int array[][5] = {
		{543,367,1,2,12},
		{32,723,152,23,12},
		{121,23,11,323,4},
		{562,27,26,126,934},
		{632,32,45,83,39}
	};
	int rows = sizeof(array)/sizeof(array[0]);
	int result;
	result = findLargest(array, rows);
	printf("Largest Element is: %d\n", result);
	
	return 0;
}

//Defination of findLargest function
int findLargest(int (*array)[5], int rows){
	int *ptr;
	int largest = 0;
	int i = 0, j = 0;
	
	while(i < rows){
		ptr = *(array + i);
		for(j = 0; j < 5; j++){
			if(largest < *(ptr + j))
				largest = *(ptr + j);
		}
		i++;
	}
	
	return largest;
}
