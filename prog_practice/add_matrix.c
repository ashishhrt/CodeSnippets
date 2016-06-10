//WAP to add two 6*6 matrix

#include<stdio.h>

int i = 0;
int j = 0;

void findSum(int a[][6], int b[][6],int rows){
	for( i = 0; i < rows; i++){
		for(j =0; j < rows; j++){
			a[i][j] += b[i][j];
		}
	}
}

//Driver function
int main(void){
	int a[][6] = {
		{43,41,6,56,67,21},
		{32,4,54,84,2,34},
		{83,872,1,34,2,34},
		{81,48,59,73,14,45},
		{84,23,43,35,47,34},
		{95,43,65,32,12,45}
	};
	int b[][6] = {
		{43,41,6,56,67,21},
		{81,48,59,73,14,45},
		{95,43,65,32,12,45},
		{32,4,54,84,2,34},
		{83,872,1,34,2,34},
		{84,23,43,35,47,34}
	};
	int rows = sizeof(a)/sizeof(a[0]);

	findSum(a, b, rows);
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < rows; j++){
			printf("%3d\t",a[i][j]);

		}
		printf("\n");
	}
	
	return 0; 
}
