//WAP to find the occurance of a string(str1) in a set of strings(str) and replace with another string(str2) 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 6

int main(void)
{
	char *str[] = {                     //array of pointers to string
		"We will teach you how to...",
		"Move a mountain",
		"Level a building",
		"Erase the past",
		"Make a million",
		"...all through C!",
	};
	char strin[50];
	char *str1,*str2;
	char *cmp,*p;
	int i = 0,count = 0;

	printf("Enter 1st string:\t");
	scanf("%s",strin);
	
	str1 = (char *)malloc(strlen(strin)+1);
	strcpy(str1,strin);
	
	printf("Enter 2nd string:\t");
	scanf("%s",strin);
	if(strlen(strin) > strlen(str1)){
		printf("INVALID INPUT Enter the 2nd string smaller than 1st string\n");
		return 1;
	}

	str2 = (char *)malloc(strlen(strin)+1);
	strcpy(str2,strin);
	
	for(i = 0; i < LEN; i++){
		cmp = strstr(str[i],str1);    //searching for the occurance of substring

		if(cmp != NULL){
			printf("'%s' found in '%s' \n",str1,str[i]);
			int n;
			n = strlen(str[i]) - strlen(cmp);

			strncpy(strin,str[i],n);
			if(strin[n] != '\0')
				strin[n] = '\0';

			strcat(strin,str2);
			
			if(strlen(cmp) > strlen(str1)){
				n += strlen(str1);
				strcat(strin,str[i]+n);
			}
			p = (char *)malloc(strlen(strin)+1);
			strcpy(p, strin);
			str[i] = p;
			printf("'%s' after replacing '%s' with '%s'\n", str[i],str1,str2);
			count = 1;
		}
	}
	if(count == 0){
		printf("No string match found for %s\n",str1);
	}

	return 0;
}