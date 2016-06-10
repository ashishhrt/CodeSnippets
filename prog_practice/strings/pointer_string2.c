//WAP to demostrate the different limitations of string and pointer notations

#include<stdio.h>

int main(void){
	char str[] = "Hello";   //Here str[] is a constant pointer to a string
	char* p = "Hey!";       //Here P is a pointer to a constant string

	/*once a string is defined it can not be initialized with other set of characters*/
	str = "Byee"; /*error*/

	/*while a pointer can point to even a different string*/
	p = "Hii"; /*perfectly good*/

	return 0;
}