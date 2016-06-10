//WAP to print a string using the fact it is terminated by '\0' character
#include<stdio.h>

int main(void){
	char str[] = "Programming";
	int i = 0;

	while(str[i] != '\0'){
		printf("%c",str[i]);
		i++;
	}
	printf("\n");

	return 0;
}