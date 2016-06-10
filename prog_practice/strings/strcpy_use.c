//WAP to show the usage of strcpy() function

#include<stdio.h>
#include<string.h>

int main(void){
	char source[] = "Ashish Kumar";
	char target[25] = "hey";
	//char* target = "hey";
	strcpy(target, source);

	printf("source string '%s' and target string '%s'\n",source,target);

	return 0;
}