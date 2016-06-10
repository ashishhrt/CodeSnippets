//WAP to find a square matrix is square matrix or not

#include<stdio.h>

int findSymmetric(int a[][4],int rows){
	int i = 0, j = 0;
	int result = 1;
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < rows; j++){
			if(a[i][j] != a[j][i]){
				result = 0;
				break;
			}
		}
		if(result == 0)
			break;
	}
	
	return result;
}

//Driver function
int main(void){
	int a[][4] = {
		43,5,54,65,
		5,23,63,76,
		54,63,90,21,
		65,76,21,9
	};
	int rows = sizeof(a)/sizeof(a[0]);
	int result = 0;
	
	result = findSymmetric(a, rows);
	if(result == 1)
		printf("\nGiven Matrix is Symmetric matrix.\n");
	else
		printf("\nGiven Matrix is NOT symmetric matrix.\n");
		
	return 0;
}
