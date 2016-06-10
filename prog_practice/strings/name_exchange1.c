//WAP to exchange names using 2-D array of characters
#include<stdio.h>
#include<string.h>

//exchange raman and srinivas
int main(void){
	char names[][10] = {
		"akshay",
		"parag",
		"raman",
		"srinivas",
		"gopal",
		"rajesh"
	};
	int i = 0;
	char temp;

	printf("Before exchnage %s %s\n",names[2],names[3]);
	for(i = 0; i < 10; i++){
		temp = names[2][i];
		names[2][i] = names[3][i];
		names[3][i] = temp;
	}
	printf("After exchange %s %s\n",names[2],names[3]);

	return 0;
}