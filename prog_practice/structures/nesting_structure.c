//WAP to demonstrate the nesting of structure inorder to make complex data types
#include<stdio.h>

int main(void){
	struct address{
		char phone[11];
		char city[10];
		int pin;
	};

	struct emp{
		char name[25];
		struct address a;
	};

	struct emp e1 = {"Ashish Kumar", {"8006171925","Delhi",201204}};

	printf("%s\t%s\t%s\t%d\n",e1.name,e1.a.phone,e1.a.city,e1.a.pin);

	return 0;
}