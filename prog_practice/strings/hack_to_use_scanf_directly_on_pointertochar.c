//A hack to use scanf function to take input with unitialized pointer to character
#include<stdio.h>

int main(void){
	char *text;
	scanf("%m[^\n]s",&text);
	printf("%s\n",text);
	return 0;
}