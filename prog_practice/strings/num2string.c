//WAP to take input of atmost 9 digit number and print number in words
#include<stdio.h>
#include<string.h>

//Declaration of function convert
char* convert(long, char *);

char *one[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen",
	"Seventeen","Eighteen","Nineteen"	
};
char *ten[] = {"","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};

//Driver function
int main(void){
	long num;

	printf("Enter a number(Max 9 digit long):\t");
	scanf("%ld",&num);

	if(num < 0){
		printf("No negetive number please!\n");
		return 1;
	}
	else{
		printf("%s ",convert((num/10000000)," Carore"));
		num = num % 10000000;
		printf("%s ",convert((num/100000)," Lakh"));
		num = num % 100000;
		printf("%s ",convert((num/1000)," Thousand"));
		num = num % 1000;
		printf("%s ",convert((num/100)," Hundred"));
		num = num % 100;
		printf("%s",convert(num,""));
	}

	printf("\n");

	return 0;
}
char ch[50];
//Defination of convert function
char* convert(long num, char* str){
	int i, j;
	
	if(num < 20){
		strcpy(ch,one[num]);
	}
	else{
		//printf("i = %d\tj=%d\n",i,j);
		i = num / 10;
		j = num % 10;
		strcpy(ch,ten[i]);
		//printf("%s\n",ch);
		strcat(ch,one[j]);
		//printf("%s\n",ch);
		//printf("%s\n",ch);
	}
	strcat(ch, str);

	return ch;
}