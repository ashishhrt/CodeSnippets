//WAP to write a xstrcmp() function same as strcmp()

#include<stdio.h>

//Declaration of xstrcmp function
int xstrcmp(const char*, const char*);

//Driver function
int main(void){
	char str1[] = "ashish";
	char str2[] = "ashishhrt";
	int i,j,k;

	i = xstrcmp(str1, "ashish");
	j = xstrcmp(str2, "ashIshhrt");
	k = xstrcmp(str1, str2);

	printf("%d %d %d\n", i,j,k);

	return 0;
}

//defination of xstrcmp() function
int xstrcmp(const char* str1, const char* str2){
	int diff = 0;
	while((*str1 != '\0') || (*str2 != '\0')){
		diff = *str1 - *str2;
		if(diff !=0){
			return diff;
		}
		str1++;
		str2++;
	}
	return diff;
}