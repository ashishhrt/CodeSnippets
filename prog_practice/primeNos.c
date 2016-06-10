//Print out prime numbers between 1-100 using sieve of Eratosthenes procedure

#include<stdio.h>

void primeNos(int a[], int size);              //Declaration of PrimeNos function

//Driver function
int main(void){
	int a[100];                 //array to contain nos from 1-100
	int i = 0;
	int size = 100;
	
	for(i = 0; i < size; i++){
		a[i] = i+1;
	}
	primeNos(a, size);
	
	printf("Prime Numbers between 1-100 are:\n");
	for(i = 1; i < size; i++){
		if(a[i] != 0)
			printf("%d, ",a[i]);
	}
	printf("\n");
	
	return 0;
}

//Defination of primeNos function
void primeNos(int a[], int size){
	int i = 1;
	int j = 0;
	int mul = 0;
	
	while(i < size){
		
		for(j = 2; j <= size/2; j++){
			mul = a[i] * j;
			if(mul <= size){
				a[mul-1] = 0;
			}
			else{
				break;
			}
		}
		i += 1;
		while(a[i] == 0)
			i++;
	}
}
