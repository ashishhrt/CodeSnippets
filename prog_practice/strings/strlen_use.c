//WAP to show the use of strlen() function

#include<stdio.h>
#include<string.h>

int main(void){
	char str[] = "hey this is my string";
	int len1, len2;

	len1 = strlen(str);
	len2 = strlen("Fuck OFF!");

	printf("lenght of '%s' is %d\n",str,len1);
	printf("length of '%s' is %d\n","Fuck OFF!",len2);
	printf("Important thing strlen() does not count '\\0' in length\n");
	return 0;
}