//WAP to show the use of gets() and puts() functio

#include<stdio.h>

int main(void){
	char str[20];
	printf("Enter a string:\t");
	gets(str);
	puts(str);

	return 0;
}