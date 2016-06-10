//WAP to find the determinant value of a 6*6 matrix

#include<stdio.h>
#include<math.h>

long int determinant(int a[][6], int rows){
	int i = 0, j = 0, k = 0,l = 0, m= 0, n = 0;
	long int result = 0;
	int icount = 1;
	for(i = 0; i < rows; i++){
		
		int jcount = 1;
		long int iresult = 0;
		
		for( j = 0; j < rows; j++){
			if( j == i)
				continue;
				
				int kcount = 1;
				long int jresult = 0;
					
			for(k = 0; k < rows; k++){
				if( k == j || k == i)
					continue;
				
				int lcount = 1;
				long int kresult = 0;
				
				for(l = 0; l < rows; l++){
					if(l == k || l == j || l == i)
						continue;
					
					int mcount = 1;
					long int lresult = 0;
					
					for(m = 0; m < rows; m++){
						if(m == l || m == k || m == j || m == i)
							continue;
						
						//int mcount = 1;
						long int mresult = 0;
						
						for(n = 0; n < rows; n++){
							if(n == m || n == l || n == k || n == j || n == i)
								continue;
							if(mcount % 2 != 0)	
								mresult = a[4][m] * a[5][n];
							else
								mresult = (-1*a[4][m] * a[5][n]);
								
							//printf("mresult = %ld\n",mresult);
						}
						mcount++;
						lresult = lresult + mresult;
						
						//printf("lresult = %ld\n",lresult);
					}
					
					if(lcount % 2 != 0)
						kresult = kresult + (a[3][l] * lresult);
					else
						kresult = kresult + (-1*a[3][l] * lresult);
					
					lcount++; 
					//printf("kresult = %ld\n",kresult);
				}
				
				if(kcount % 2 != 0)
					jresult = jresult + (a[2][k] * kresult);
				else
					jresult = jresult + (-1 * a[2][k] * kresult);
					
				kcount++;
				//printf("jresult = %ld\n",jresult);
			}
			
			if(jcount % 2 != 0)
				iresult = iresult + (a[1][j] * jresult);
			else
				iresult += (-1 * a[1][j] * jresult);
				
			jcount++;
			//printf("iresult = %ld\n",iresult);
		}
		
		if(icount % 2 != 0)
			result += (a[0][i] * iresult);
		else
			result += (-1 * a[0][i] * iresult);
			
		//printf("%ld  %d\n",result,icount);
		icount++;
	}
	
	return result;
}

//Driver function
int main(void){
	int a[6][6];
	/* = {
		{12,23,4,1,3,4},
		{4,32,4,2,5,5},
		{8,4,5,2,32,12},
		{7,9,15,14,3,4},
		{9,5,2,7,3,21},
		{7,1,3,17,12,11}
	};
	*/
	int rows = 6;
	int i = 0, j = 0;
	long int result;
	
	//result = determinant(a, rows);
	printf("Enter the elements of 6*6 matrix row wise\n\n");
	for(i = 0; i < rows; i++){
		printf("row %d\n", i+1);
		for(j = 0; j < rows; j++){
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nMatrix entered:\n");
	for(i = 0; i < rows; i++){
		for(j = 0; j < rows; j++){
			printf("%3d\t",a[i][j]);
		}
		printf("\n");
	}
	
	result = determinant(a, rows);
	
	printf("\ndeterminat = %ld\n",result);
	
	return 0;
}

