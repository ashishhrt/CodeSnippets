//WAP to demostrate the passing of address of structure variable
#include<stdio.h>
struct book{
	char name[20];
	char author[20];
	int callno;
};
void display(struct book *a){
	printf("%s\t%s\t%d\n",a->name,a->author,a->callno);
}

int main(void){
	struct book b1 = {"Who knows","A must know",5467456};

	display(&b1);

	return 0;	
}