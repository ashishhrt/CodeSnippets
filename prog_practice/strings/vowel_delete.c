//WAP to delete all the vowels from a sentence.Assume sentence not longer than 80 characters
#include<stdio.h>
#include<string.h>
#define LEN 80
void find_vowels(char p[]){
	int len = strlen(p);
	char vowels[] = {'a','e','i','o','u'};
	int i = 0,j = 0;
	for(i = 0; i < len; i++){
		for(j = 0; j < 5; j++){
			if(p[i] == vowels[j] || p[i] == (vowels[j] - 32)){
				p[i] = '0';
			}
		}
	}
}
//Driver function
int main(void){
	char str[LEN+1];                //array to hold sentence
	int i,j;

	printf("Enter the stentence of at most 80 characters:\n");
	gets(str);                 //input string

	if(strlen(str) > LEN){
		printf("String longer than allowed\n");
		return 1;
	}

	find_vowels(str);

	for(i = 0; i < strlen(str); i++){
		if(str[i] == '0'){
			for(j = i; j < strlen(str); j++){
				str[j] = str[j+1];
			}
			i -= 1;
		}
	}
	printf("String after deleting vowels:\n%s\n",str);

	return 0;
}