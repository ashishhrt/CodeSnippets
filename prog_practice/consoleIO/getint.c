//WAP to write getint() function which receives numeric string convert it into corresponding integer and return the integer
#include<stdio.h>

long int getint();                //declaration

//driver function
int main(void){
	int num;

	num = getint();
	printf("The Number you entered:\t%d\n",num);

	return 0;
}

long int getint(){
	long int a = 0;
	int neg = 0;
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