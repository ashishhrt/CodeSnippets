//WAP to print the string using pointer
#include<stdio.h>

int main(void){
	char str[] = "Programming";
	char* ptr = str;

	while(*ptr != '\0'){
		printf("%c",*ptr);
		ptr++;
	}
	printf("\n");

	return 0;
}