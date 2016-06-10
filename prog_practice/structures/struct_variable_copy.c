//WAP to demonstrate the copying of structure variable by piece-meal and direct copying
#include<stdio.h>
#include<string.h>

int main(void){
	struct book {
		char name[20];
		float price;
		int pages;
	};

	struct book b1 = {"C is amazing",78.45,890};
	struct book b2,b3;

	//peice-meal copying
	strcpy(b2.name,b1.name);
	b2.price = b1.price;
	b2.pages = b1.pages;

	//one go copying
	b3 = b1;

	printf("%s\t%f\t%d\n",b1.name,b1.price,b1.pages);
	printf("%s\t%f\t%d\n",b2.name,b2.price,b2.pages);
	printf("%s\t%f\t%d\n",b3.name,b3.price,b3.pages);

	return 0;
}