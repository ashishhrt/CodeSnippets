//WAP to exchange names using array of pointers to strings
#include<stdio.h>
#include<string.h>

//exchnage ramesh and srinivas
int main(void){
	char *name[] = {
		"akshay",
		"parag",
		"raman",
		"srinivas",
		"gopal",
		"rajesh"
	};
	char *temp;

	printf("before exchange %s %s\n",name[2],name[3]);
	temp = name[2];
	name[2] = name[3];
	name[3] = temp;
	printf("after exchange %s %s\n",name[2],name[3]);

	return 0;
}