//WAP for multiplying very large numbers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

int *multiply(int *, int, int *, int);

int main(void){
	char number[MAX];           //hold the input number
	int len1, len2;
	int *n1, *n2, *result;
	int i, j;

	printf("Enter a number:\t");
	scanf("%s",number);

	len1 = strlen(number);
	n1 = (int *)malloc(sizeof(int) * len1);

	for(i = 0; i < len1; i++){
		n1[i] = (number[i] - 48);
	}
	printf("Enter a number:\t");
	scanf("%s",number);

	len2 = 	strlen(number);
	n2 = (int *)malloc(sizeof(int) *len2);

	for(i = 0; i < len2; i++){
		n2[i] = (number[i] - 48);
	}

	printf("\nNumber 1: ");
	for(i = 0; i < len1; i++){
		printf("%d",n1[i]);
	}

	printf("\nNumber 2: ");
	for(i = 0; i < len2; i++){
		printf("%d",n2[i]);
	}

	printf("\n\n");
	if(len1 >= len2)
		result = multiply(n1, len1, n2, len2);
	else
		result = multiply(n2, len2, n1, len1);

	printf("Result = ");

	j = len1 + len2;
	for(i = 0; i < j; i++){
		printf("%d",result[i]);
		if(i > 0 && (i+1)% 3 == 0)
			printf(" ");
	}

	printf("\n\n");
}

int *multiply(int *n1, int len1, int *n2, int len2){
	int *result = (int *)malloc(sizeof(int) * (len1+len2));
	int i,j,k,l, len,counter;
	long unsigned int carry = 0;
	long unsigned int temp = 0;

	len = len1+len2;
	counter = len;

	for(i = (len1-1), j = (len2-1); i > -1; i--, j--){
		k = (len2-1);
		l = i;
		if(j < 0)
			j = 0;

		//printf("\nInside 1st for carry = %ld", carry);
		while(l < len1 && k > j-1){
			temp += n1[l] * n2[k];
			
			l++;
			k--;
		}

		result[--counter] = temp % 10;
		//printf("\nInside 1st for temp = %ld", temp);
		carry = temp/10;
		temp = carry;
	}

	
	for(i = (l-1), j = (len2-2); i > 0; i--, j--){
		k = j;
		l = 0;

		//printf("\nInside 2nd for carry = %ld", carry);

		while( k > -1 && l < i){
			temp += n1[l] * n2[k];

			l++;
			k--;
		}

		result[--counter] = temp % 10;
		//printf("\nInside 2nd for temp = %ld", temp);
		carry = temp/10;
		temp = carry;
	}

	if(temp > 0 && counter > 0){
		while(temp != 0 && counter > -1){
			result[--counter] = temp %10;
			temp /= 10;
		}
	}

	//printf("\nEnd of multilply carry = %ld\tcounter = %d\n", carry,counter);
	return result;
}