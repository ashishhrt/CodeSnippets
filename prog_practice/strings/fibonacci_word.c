//WAP that generates fibonacci word of order 0 through 5
#include<stdio.h>
#include<string.h>

int main(void){
	char word[20];
	char previous[20] = "B";
	char prev_2_prev[20] = "A";
	int i = 0;

	for(i = 1; i <= 5; i++){
		strcpy(word,previous);
		strcat(word,prev_2_prev);
		printf("%s\t",prev_2_prev);
		strcpy(prev_2_prev, previous);
		strcpy(previous, word);
	}
	printf("%s\t%s\n",prev_2_prev, previous);

	return 0;
}