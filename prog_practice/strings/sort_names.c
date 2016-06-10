//WAP to sort a set of names stored in an array in alphabetical order
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 5

//Declaration of xtrcmp
int xstrcmp(char *, const char *);

//Driver function
int main(void){
	char name[SIZE][20];
	char *p;
	int i,j;

	printf("Enter %d name:\n",SIZE);
	for(i = 0; i < SIZE; i++){
		printf("Name: ");
		scanf("%s",name[i]);
	}
	//Applying selection sort
	for(i = 0; i < (SIZE -1); i++){
		for(j = i+1; j < SIZE; j++){
			if(xstrcmp(name[i],name[j]) > 0){           //calling xstrcmp() to find the priorty of comparison strings 
				p = (char *)malloc(strlen(name[i])+1);
				strcpy(p,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],p);
			}
		}
	}
	printf("Names in sorted order:\n");
	for(i = 0; i < SIZE; i++){
		printf("%s\n",name[i]);
	}

	return 0;
}

//Defination of xstrcmp function
int xstrcmp(char *str1, const char *str2){
	char temp[2];
	int diff = 0;
	while(*str1 != '\0' || *str2 !='\0'){
		if(*str1 >= 65 && *str1 <= 90)
			temp[0] = *str1 + 32;
		else
		temp[0] = *str1;
		
		if(*str2 >= 65 && *str2 <= 90)
			temp[1] = *str2 + 32;
		else
			temp[1] = *str2;

		diff = temp[0] - temp[1]; 
		if(diff != 0){
			break;
		}
		str1++;
		str2++;
	}

	return diff;
}