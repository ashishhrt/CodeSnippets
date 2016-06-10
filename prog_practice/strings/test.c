#include<stdio.h>

int main(void){
	char *str = 'A';
	char *p;

	p = &str;
	*p = 'e';

	printf("%c\n",str);

	return 0;
}