//WAP to count the number of occurance of two vowels in succession
//eg: "The love of my life is gratuity"     ui
#include<stdio.h>
#include<string.h>
#define LEN 60
int find_vowel(char ch){
	char vowel[] = {'a','e','i','o','u'};
	int check = 0,i;
	for(i = 0; i < 5; i++){
		if(ch == vowel[i] || ch == (vowel[i]-32)){
			check = 1;
			break;
		}
	}

	return check;
}
//Driver function
int main(void){
	char str[LEN+1];
	char *p;
	int count = 0;

	printf("Enter a Sentence not longer than %d:\n",LEN);
	gets(str);
	if(strlen(str) > LEN){
		printf("Lenght of string exceeds %d\n",LEN);
		return 1;
	}
	p = str;
	while(*p != '\0'){
		if(find_vowel(*p)){
			if(find_vowel(*(p+1)))
				count++;
		}
		p++;
	}

	printf("\n%d times two vowels ocuured in succession in the given string\n",count);

	return 0;
}