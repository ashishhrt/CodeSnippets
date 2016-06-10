//WAP a function xstrcat() same as strcat()

#include<stdio.h>

//xstrcat function declaration
void xstrcat(char*, const char*);

//Driver function
int main(void){
	char source[] = "Kumar is awesome";
	char target[50] = "Ashish ";

	xstrcat(target, source);

	printf("Source string = '%s'\n",source);
	printf("target string = '%s'\n",target);

	return 0;
}

//defination of xstrcat() function
void xstrcat(char* target, const char* source){
	while(*target != '\0')
		target++;

	while(*source != '\0'){
		*target = *source;
		target++;
		source++;
	}
	*target = '\0';
}