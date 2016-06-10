//WAP to show the memory map of structure elements
#include<stdio.h>

int main(void){
	struct book {
		char name;
		float price;
		int pages;
	};

	struct book b1 = {'A',45.56,123};

	printf("Address of name = %p\n",&b1.name);
	printf("Address of price = %p\n",&b1.price);
	printf("Address of pages = %p\n",&b1.pages);

	return 0;
}