//WAP to demonstrate passing the individual elements of a structure variable to a function
#include<stdio.h>

void display(char *,float, int);

int main(void){
	struct book{
		char name[10];
		float price;
		int pages;
	};

	struct book b1 = {"Yog",67.23,679};
	display(b1.name,b1.price,b1.pages);
	
	return 0;
}

void display(char *name, float price, int pages){
	printf("%s\t%f\t%d\n",name,price,pages);
}