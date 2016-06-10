//WAP to demostrate all the ways by which a struct variable can be declared
#include<stdio.h>

int main(void){
	struct book1{
		char name;
		float price;
		int pages;
	};
	//method 1
	struct book1 b1 = {'a',56.97,523};                        //just like normal variables struct variables can also be initialized 
	struct book1 b2 = {'b',23.5,456};                     

	struct book2{
		char name;
		float price;
		int pages;
	}b21,b22;                             //method 2

	struct {
		char name;
		float price;
		int pages;
	}b31,b32;                            //method 3

	printf("Enter the name, price, pages of 4 books:\n");

	scanf(" %c%f%d",&b21.name,&b21.price,&b21.pages);
	scanf(" %c%f%d",&b22.name,&b22.price,&b22.pages);
	scanf(" %c%f%d",&b31.name,&b31.price,&b31.pages);
	scanf(" %c%f%d",&b32.name,&b32.price,&b32.pages);

	printf("This is what data collected:\n");
	printf("\nStruct 1:\n");
	printf("%c\t%f\t%d\n",b1.name,b1.price,b1.pages);
	printf("%c\t%f\t%d\n",b2.name,b2.price,b2.pages);

	printf("\nStruct 2:\n");
	printf("%c\t%f\t%d\n",b21.name,b21.price,b21.pages);
	printf("%c\t%f\t%d\n",b22.name,b22.price,b22.pages);

	printf("\nStruct 3:\n");
	printf("%c\t%f\t%d\n",b31.name,b31.price,b31.pages);
	printf("%c\t%f\t%d\n",b32.name,b32.price,b32.pages);

	return 0;
}