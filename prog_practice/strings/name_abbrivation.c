//WAP take full name of an individual and abbrivate it but not the last name
#include<stdio.h>
#include<string.h>
#define LEN 40
int main(void){
	char name[LEN+1], fname[10];
	char *p,*s,*temp2;
	char temp;
	printf("Enter your name:\t");
	gets(name);

	if(strlen(name) > LEN){
		printf("Length of name exceeded\n");
		return 1;
	}
	p = name;
	s = fname;
	temp = p[0];
	temp2 = p;
	while(*p != '\0'){
		if(*p == 32){
			*s = temp;
			s++;
			temp = *(p+1);
			temp2 = p+1;
		}
		p++;
	}
	*s = '\0';
	s = fname;
	printf("Name after abbrivation:\t");
	while(*s != '\0'){
		printf("%c ", (*s >= 65 && *s <= 90)?*s:(*s-32));
		s++;
	}
	if(*temp2 >=97 && *temp2 <= 122)
		*temp2 -= 32;
	printf("%s\n",temp2);

	return 0;
}