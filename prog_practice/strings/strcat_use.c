//WAP to show the usage of strcat() string function

#include<string.h>
#include<stdio.h>

int main(void){
	char source[] = "Kumar is awesome";
	char target[50] = "Ashish ";

	strcat(target, source);

	printf("source string = '%s'\n",source);
	printf("Taget string = '%s'\n",target);

	return 0;
}
