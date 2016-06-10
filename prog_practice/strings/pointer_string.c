//WAP to demonstrate pointers and strings

#include<stdio.h>

int main(void){
	char str1[] = "Hello My string";
	char str2[20];
	char* ptr = "My name is anthony";
	char* ptr2;

	str2 = str1; /*error because string can not be assigned to another string*/
	ptr2 = ptr; /*perfectly good because a pointer to string can be assigned to different pointer*/

	return 0;
}