//A hack to make scanf accept multi-word string

#include<stdio.h>

int main(void){
	char str[30];

	printf("Enter a string:\t");
	scanf("%[^\n]s",str);       //%[^\n]s tells to accept the string till new line character is not input
	printf("%s\n", str);

	return 0;
}