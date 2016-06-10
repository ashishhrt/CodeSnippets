//WAP to implement xgets() ang xputs() which work same as standard library functions gets() and puts()
#include<stdio.h>

char *xgets(char *);
int xputs(const char *);

int main(void){
	char text[50];
	xputs("Enter a string");
	xgets(text);
	xputs(text);

	return 0;
}

//defination of xgets()
char *xgets(char *s){
	char *ptr = s;
	char ch;

	do{
		ch = getchar();
		if(ch == EOF){
			return NULL;
		}
		else{
			*ptr = ch;
			ptr++;
		}
	}
	while(ch != '\n' && ch != EOF);
	
	ptr -= 1;
	*ptr = '\0';
	return s;
}

//defination of xputs()
int xputs(const char *s){
	int count = 0,status = 1;
	while(*s != '\0'){
		status = putchar(*s);
		if(status == EOF){
			return EOF;
		}
		s++;
		count++;
	}
	printf("\n");
	return 0;
}
