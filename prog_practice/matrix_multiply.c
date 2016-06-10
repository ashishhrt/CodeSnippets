//WAP to multiplay any two 3*3 matrix

#include<stdio.h>

int i = 0;
int j = 0;
int k = 0;

int multiply_matrix(int a[][3], int b[][3],int r[][3], int rows){
	for( k = 0; k < rows; k++){
		for(i = 0; i < rows; i++){
			for(j = 0; j < rows; j++){
				r[k][i] += (a[k][j] * b[j][i]);
			}
		}
	}
}

//Driver function
int main(void){
	int a[][3]={
		{14,20,3},
		{21,34,1},
		{12,2,23}
	};
	int b[][3]={
		{12,4,5},
		{54,6,7},
		{23,5,8}
	};
	int result[3][3] = {
		0,0,0,
	};
	int rows = sizeof(a)/sizeof(a[0]);
	
	multiply_matrix(a, b, result, rows);
	
	printf("Result of matrix multiplication:\n");
	
	for( i = 0; i < rows; i++){
		for( j = 0; j < rows; j++){
			printf("%5d\t",result[i][j]);	
		}
		printf("\n");
	}
	
	return 0; 
}
