#include<stdio.h>

/*void change(int** ptp){
	printf("*ptp = %p\n", *ptp);
	*ptp++;
	printf("*ptp = %p\n", *ptp);
}
*/
int main(void){
	int b = 5;
	int a;
	/*int *ptr = &b;
	printf("ptr = %p\n", ptr);
	change(&ptr);
	printf("ptr = %p\n", ptr);
	*/
	while(1){
		printf("\nEnter\t:");
		a = scanf("%d",&b);
		if(a==0){
		printf("error\n");
		while(getchar() != '\n');
		}
		if(b == 0)
			break;
	}
	return 0; 
}
