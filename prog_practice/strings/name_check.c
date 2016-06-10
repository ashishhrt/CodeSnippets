//WAP to enter a name and then check whether its allowed to enter the palace or not using 2-D array of characters
#include<stdio.h>
#include<string.h>
#define FOUND 1
#define NOTFOUND 0

int main(void){
	char mastername[][10] = {
		"ashish",
		"rahul",
		"ketan",
		"abhay",
		"rashid",
		"kaleshwar",
		"rohan",
		"roshni",
		"neha",
		"sneha"
	};

	char name[40];
	int i = 0, k;
	int flag = NOTFOUND;

	printf("Enter your name:\t");
	scanf("%s",name);

	for(i = 0; i < 10; i++){
		k = strcmp(name,mastername[i]);
		if(k == 0){
			flag = FOUND;
			break;
		}
	}

	if(flag == FOUND){
		printf("%s you are welcome to the palace!\n",name);
	}
	else{
		printf("Sorry you are a trespasser!\n");
	}

	return 0;
}