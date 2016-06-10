//WAP to demostrate the passing of structure variable as a whole to a function just like a normal variable
#include<stdio.h>

struct book{
	char name[20];
	char author[20];
	int callno;
};

void display(struct book);

int main(void){
	struct book b1 = {"Yog Vani","Guru",53748};

	display(b1);          //passing the structure variable as a whole

	return 0;	
}

void display(struct book b){
	printf("%s\t%s\t%d\n",b.name,b.author,b.callno);
}