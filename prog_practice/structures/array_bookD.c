//WAP to demonstrate storing data of 3 books using array method
#include<stdio.h>

int main(void){
	char name[3];
	float price[3];
	int pages[3];
	int i = 0;

	printf("Enter the name, price, number of pages of 3 books:\n");
	for(i = 0; i < 3; i++){
		scanf(" %c%f%d",&name[i],&price[i],&pages[i]);
	}

	printf("And this is what you entered!\n");
	for(i = 0; i < 3; i++){
		printf("%c\t%f\t%d\n",name[i],price[i],pages[i]);
	}

	return 0;
}