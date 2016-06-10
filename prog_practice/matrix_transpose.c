//WAP to find the transpose of a 4*4 matrix

#include<stdio.h>

void find_transpose(int a[][4], int rows){
	int i = 0, j = 0,k = 0;
	int interchange = 0;
	
	//printf("ardress : %p\n", a);
	for(i = 0; i < rows; i++){
		for(j = k; j < rows; j++){
			if(i == j)
			;
			else{
				interchange = a[i][j];
				//printf("a[i][j] = %d\n",a[i][j]);
				//printf("a[j][i] = %d\n",a[j][i]);
				a[i][j] = a[j][i];
				a[j][i] = interchange;
				
				//printf("a[i][j] = %d\n",a[i][j]);
				//printf("a[j][i] = %d\n",a[j][i]);
				//printf("\n");
			}
			printf("%d   ",a[i][j]);
		}
		k++;
		printf("\n");
	}
}

//Driver function
int main(void){
	int array[][4] = {
		{54,34,2,43},
		{32,45,22,56},
		{43,53,6,23},
		{545,7,87,85}
	};
	int rows = sizeof(array)/sizeof(array[0]);
	int i = 0, j = 0;
	//printf("adress : %p\n", array);
	find_transpose(array, rows);
	printf("Matrix transpose:\n");
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < rows; j++){
			printf("%3d  ",array[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
