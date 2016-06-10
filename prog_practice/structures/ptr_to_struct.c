//WAP to demostrate the use of pointer to structure
#include<stdio.h>

int main(void){
	struct book{
		char name[20];
		char author[20];
		int callno;
	};

	struct book b1 = {"Yes We can!","I don't know",763439509};
	struct book *ptr;

	ptr = &b1;

	printf("%s\t%s\t%d\n",b1.name,b1.author,b1.callno);
	printf("%s\t%s\t%d\n",ptr->name,ptr->author,ptr->callno);

	return 0;
}