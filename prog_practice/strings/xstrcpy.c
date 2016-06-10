//WAP to write a function xstrcpy() same as strcpy()

#include<stdio.h>

//xstrcpy function declaration
void xstrcpy(char*,const char*);

//driver function
int main(void){
	char source[] = "Ashish Kumar";
	char target[20];

	xstrcpy(target, source);

	printf("souce string = '%s'\n", source);
	printf("target string = '%s'\n",target);

	return 0;
}

//defination of xstrcpy function
void xstrcpy(char* target, const char* source){   //we took source pointer as constant to avoide any accidental change in thr source string
	while(*source != '\0'){
		*target = *source;
		target++;
		source++;
	}
	*target = '\0';   //add '\0' character at the end manually to make it a string
}