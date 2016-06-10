//WAP to reverse the strings stored in array of pointers to strings
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 3

//xstrrev function declaration
char *xstrrev(char *, int );

//Driver function
int main(void){
	char *str[LEN]={
		"To err is human...",
		"But to really mess things up...",
		"One needs to know C!!"
	};
	int i;

	printf("\nOrignal Strings:\n");
	for(i = 0; i < LEN; i++){
		printf("'%s'\n",str[i]);
		str[i] = xstrrev(str[i],strlen(str[i]));
	}

	printf("\nStrings after reversed:\n");
	for(i = 0; i < LEN; i++){
		printf("'%s'\n",str[i]);
	}

	return 0;
}

//xstrrev function defination
char *xstrrev(char *st,int size){
	char str[size];
	char *p;
	int len;

	strcpy(str,st);
	len = strlen(str);
	p = (char *)malloc(strlen(str)+1);
	
	while(len > 0){
		while((len > 0) && (*(str+len) != 32)){
			len--;
		}
		if(len > 0){
			strcat(p,(str+len+1));
			strcat(p, " ");
			*(str+len) = '\0';
			len--;
		}
		else
			strcat(p,(str+len));
	}

	return p; 
}

/*//----yshwant kanetkar's solution---------
void xstrrev(char *ss,int size){
	int l,i;
	char *tt,temp;

	l = size;
	tt = ss + l - 1;

	for(i = 1; i <= l/2; i++){
		temp = *ss;
		*ss = *tt;
		*tt = temp;
		ss++;
		tt--;
	} 
}
*/