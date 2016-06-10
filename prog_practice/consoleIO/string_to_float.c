//WAP to write getfloat() function which receives numeric string convert it into corresponding float and return the float
#include<stdio.h>

float getfloat();                //declaration

//driver function
int main(void){
	float num;

	num = getfloat();
	printf("The Number you entered:\t%f\n",num);

	return 0;
}

float getfloat(){
	float a = 0;
	int neg = 0,int count = 0;
	char ch;

	do{
		ch = getchar();
		if(ch == '\n')
			continue;
		else if(ch == 45)
			neg = 1;
		else if(ch < 48 || ch > 57){
			return EOF;
		}
		else{
			a = a*10 + (ch - 48);
		}
	}
	while(ch != '\n');
	if(neg == 1){
		a *= -1;
	}
	return a;
}