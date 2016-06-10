//WAP to take string input from scanf using %S format specifier
//NOTE scanf can take 1 word as input at a time. (e.g: "Ashish kumar" is invalid)

#include<stdio.h>

int main(void){
	char str[10] ;
	//char str2[10];

	printf("Enter your name:\t");
	scanf("%s",str);
	//scanf("%s",str2);
	printf("Hello! %s\n",str);

	return 0; 
}