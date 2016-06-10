//WAP consider a p[5] array write a function to circularly left shift the array and use it shift rows of an 4*5 array

#include<stdio.h>
#define ROW 4
#define COL 5

int i = 0, j = 0;

int leftShift_elements(int p[]){
	int rows = ROW;
	while(rows > 0){
		int first = p[0], second = p[1];
		printf("%p\n", p);
		for(i = 0; i < COL; i++){
		
			if(i == COL - 2)
				p[i] = first;
			else if(i == COL - 1)
				p[i] = second;
			else
				p[i] = p[i+2];
			
		}
		p += 5;
		rows--;
	}
	return 0;
}

//Driver function
int main(void){
	int a[][5] = {
		{12,32,45,42,54},
		{4,56,76,1,6},
		{56,67,8,2,62},
		{23,73,562,53,21}
	};

	
	leftShift_elements(a[0]);
	
	printf("Matrix after left shift:\n");
	for(i = 0; i < ROW; i++){
		for(j = 0; j < COL; j++){
			printf("%3d\t",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
