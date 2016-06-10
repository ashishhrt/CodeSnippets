//WAP to check whether the given solution of a sudoku is correct or not

#include<stdio.h>
//#include<conio.h>
#define SIZE 9

//Check reset function
void reset_check(int check[]){
	int i = 0;
	for(i = 0; i < SIZE; i++)
		check[i] = 0;
}
//Column check function
int column_check(int sudoku[][SIZE], int check[], int* result){
	int i,j;
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			//printf("inside column_check\n");
			if(check[sudoku[j][i]] == 1){
				*result = 0;
				return 0;
			}
		}
		reset_check(check);
	}
	return 0;
}
//Row check function
int row_check(int sudoku[][SIZE], int check[], int* result){
	int i,j;
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			//printf("inside row_check\n");
			if(check[sudoku[i][j]] == 1){
				*result = 0;
				return 0;
			}
		}
		reset_check(check);
	}
	return 0;	
}
//Grid check function
/*--------Grid check is optional----------*/
int grid_check(int sudoku[][SIZE], int check[], int* result){
	int i = 0,j = 0;
	int r = 0, c = 0;
	int n = SIZE/3;

	while(r < SIZE){
		c = 0;
		while(c < SIZE){
			for(i = r;i < r+n; i++){
				for(j = c;j < c+n; j++){
					//printf("inside grid_check i = %d\tj = %d\tr = %d\tc = %d\n",i,j,r,c);
					if(check[sudoku[i][j]] == 1){
						*result = 0;
						return 0;
					}
				}
				//j = c;
			}  
			c += n;
			//j = c;
			reset_check(check);
		}
		r += n;
		//i = r;
	}
	return 0;
}

int main(void){
	int sudoku[SIZE][SIZE] = {
		{5,3,4,6,7,8,9,1,2},
		{6,7,2,1,9,5,3,4,8},
		{1,9,8,3,4,2,5,6,7},
		{8,5,9,7,6,1,4,2,3},
		{4,2,6,8,5,3,7,9,1},
		{7,1,3,9,2,4,8,5,6},
		{9,6,1,5,3,7,2,8,4},
		{2,8,7,4,1,9,6,3,5},
		{3,4,5,2,8,6,1,7,9}
	};
	int check[SIZE] = {0,0,0,0};
	
	int result = 1;                                 //0 -> wrong, 1 - > correct
	//printf("check[sudoku[2][3]] = %d\n",check[sudoku[2][3]]);
	//Column check
	column_check(sudoku,check, &result);
	if(result == 0)
		goto x;

	//Row check
	row_check(sudoku,check, &result);
	if(result == 0)
		goto x;
	
	//Grid check
	///*
	grid_check(sudoku,check,&result);
	if(result == 0)
		goto x;
	//*/
	x:
	if(result == 0){
		printf("Sorry the given solution of %d * %d sudoku is WRONG\n", SIZE, SIZE);
	}

	if(result == 1){
		printf("The given solution of %d * %d sudoku is CORRECT\n",SIZE,SIZE);
	}

	return 0;
}