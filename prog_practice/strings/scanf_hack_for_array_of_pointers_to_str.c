//Write the hack for taking input using scanf for an array of pointers to strings
//NOTE: this hack is bit havey in consideration to performance
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
	char *name[6];
	char n[30];
	char *temp;
	int i = 0,length;

	for(i = 0; i < 6; i++){
		printf("Enter name:\t");
		scanf("%s",n);
		length = strlen(n);

		temp = (char *)malloc(length + 1);                  //Dynamically allocating memory
		strcpy(temp, n);
		name[i] = temp;
	}

	printf("Names entered:\n");
	for(i = 0; i < 6; i++){
		printf("%s\t",name[i]);
	}
	printf("\n");

	return 0;
 }