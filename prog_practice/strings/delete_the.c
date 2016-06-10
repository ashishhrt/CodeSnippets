//WAP that will read a line and delete from it all the occurance of word 'the'
#include<stdio.h>
#include<string.h>
#define LEN 50
int main(void){
	char str[LEN+1];                  //array of characters to hold the string
	char str1[LEN+1];
	char *p, *s;

	printf("Enter the string:\n");
	gets(str);
	printf("lenght = %d\n",(int)strlen(str));
	if(strlen(str) > LEN){
		printf("String longer than allowed\n");
		return 1;
	}
	s = str;
	p = str1;
	while( *s != '\0'){
		if(*(s) == 't' || *(s) == 'T'){
			if(*(s+1) == 'h'){
				if(*(s+2) == 'e'){
					s += 3;
				}
				else{
					*p = *s;
					p++;
					s++;		
				}
			}
		}
		else{
			*p = *s;
			p++;
			s++;
		}
	}
	if(*(p-1) == 32)
		*(p-1) = '\0';
	else
		*p = '\0';
	printf("String after deleting all the occurance of 'the':\n'%s'\nlength = %d\n",str1,(int)strlen(str1));

	return 0;
}