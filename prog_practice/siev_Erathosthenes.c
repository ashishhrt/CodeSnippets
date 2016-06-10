#include<stdio.h>

int main(void){
	int array[100];
	int i=0;
	for(i = 0; i < 100; i++){
		array[i] = i+1;
	}
	for(i = 1; i < 100; i++){
		if(array[i] > 0){
			int j;
			for(j = 2; array[i]*j <= 100; j++){
				int temp = array[i]*j;
				array[temp] = 0;
			}
		}
	}
	printf("Prime Numbers between 1 to 100: \n");
	for(i = 0; i < 100; i++){
		if(array[i] > 0)
			printf("%d\n",array[i]);
	}
	return 0;
}
