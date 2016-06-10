//WAP to demonstrate the use of array of structures
#include<stdio.h>

int main(void){
	struct book{
		char name;
		float price;
		int pages;
	};
	struct book b[5];                  //5 books 
	int i = 0;

	printf("Enter the name, price, pages of 5 books\n");
	for(i = 0; i < 5; i++){
		scanf(" %c%f%d",&b[i].name,&b[i].price,&b[i].pages);
	}

	printf("This is what you entered:\n");
	for(i = 0; i < 5; i++){
		printf("%c\t%f\t%d\n",b[i].name,b[i].price,b[i].pages);
	}

	return 0;
}