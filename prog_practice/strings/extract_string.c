//WAP to extract specified part of the string
//if number of characters to be extracted is 0 then extract entire string from the specified position

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//String extraction function declaration
char* ex_string(const char *, int ,int);

//driver function
int main(void){
	char p[30];
	int pos = 0, num = 0;
	char *res;

	printf("Enter a string:\t");
	gets(p);
	printf("Orignal String:\t'%s'\nEnter the position and number of characters to extract:\n",p);
	scanf("%d %d",&pos, &num);

	res = ex_string(p, pos, num);
	printf("Extracted string:\n%s\n",res);
	return 0;
}

//ex_string function defination
char* ex_string(const char* str,int pos, int num){
	int len = strlen(str);
	int i = 0;
	char res[len+1];
	char *actual_res;

	if(pos > 0)
		str = str+pos-1;
	else
		str = str + 0;
	if(num > 0 && num <= (len+1 - pos)){
		i = 0;
		while(i < num){
			res[i] = *str;
			str++;
			i++;
		}
		res[i] = '\0';
	}
	else if( num == 0){
		i = 0;
		while(i < (len+1 - pos)){
			res[i] = *str;
			str++;
			i++;
		}
		res[i] = '\0';
	}

	actual_res = (char *)malloc(strlen(res)+1);  //+1 for accomadationg the '\0'
	strcpy(actual_res, res);

	return actual_res;
}