#include<stdio.h>
#pragma pack(1)                 //32-bit microprocessor read concept of this in let us c structures page-389 
/*#pragma pack() directive specifies the packing alignment for structure elements*/
struct emp{
	int a;
	char ch;
	float s;
};
#pragma pack()
struct check{
	int b ;
	char c ;
	float f;
};

int main(void){
	struct emp e;
	struct check che;
	printf("%p\t%p\t%p\n",&e.a,&e.ch,&e.s);
	printf("%p\t%p\t%p\n",&che.b,&che.c,&che.f);

	return 0;
}