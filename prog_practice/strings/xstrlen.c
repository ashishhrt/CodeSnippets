//WAP to write a funxtion xstrlen() same as strlen()

#include<stdio.h>

//xstrlen function declaration
int xstrlen(char*);

//Driver function
int main(void){
	char str[] = "Hey hii this is my string";
	int len;

	len = xstrlen(str);

	printf("lenght of '%s' is %d\n",str,len);

	return 0;
}

//xstrlen function defination
int xstrlen(char* s){
	int count = 0;
	while(*s != 0){
		count++;
		s++;
	}

	return count;
}