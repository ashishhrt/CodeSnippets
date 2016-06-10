//WAP to demonstrate the limitation of array of pointers to strings
//NOTE: 2-D array of characters can be used to take input from the keyboard using scanf
//BUT array of pointers to strings can not be used directly to take input from keyboard using scanf
#include<stdio.h>
#include<string.h>

//This program gives runtime error
int main(void){
	char *name[6];
	int i = 0;
 
	for(i = 0; i < 6; i++){
		printf("Enter name:\t");
		scanf("%s",name[i]);    //this is not possible coz when array of pointers declared they contain garbage values and obvo garbage values can't
	}							//be used as memory addresses to store values

	return 0;
}