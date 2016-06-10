//WAP to show the usage of strcmp() string function

#include<stdio.h>
#include<string.h>

int main(void){
	char str1[] = "string1";
	char str2[] = "ashish";
	int i,j,k;
	
	i = strcmp(str1, "string1");    /*strcmp comaprison of st2 from str1*/
	j = strcmp(str2, "ashish");
	k = strcmp(str1, str2);

	printf("%d %d %d\n",i,j,k);

	return 0;
}