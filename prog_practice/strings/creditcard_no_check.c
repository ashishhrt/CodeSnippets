//WAP to check whether given credit card number is valid or not
//To see logic check ques: 'g' of Exercise of chapter String (book: YAshwant Kanetkar)

# include<stdio.h>
#include<string.h>
#define LEN 16

int main(void){
	
	char creditcard_no[17];
	int temp[8],i,j,k,sum_odd = 0,sum_even = 0;

	printf("Enter 16 digit credit card number:\t");
	scanf("%s",creditcard_no);

	if(strlen(creditcard_no) < LEN){
		printf("%s INVALID creditcard_no\n",creditcard_no);
		return 1;
	}

	for(i = 0,j=0,k=1; i < (LEN-1) && (k < LEN); i+=2,j++,k+=2){
		if(creditcard_no[i] >= 48 && creditcard_no[i] <=57 && creditcard_no[k] >= 48 && creditcard_no[k] <= 57){
			temp[j] = 2*(creditcard_no[i] - 48);
			if(temp[j] >= 10){
				temp[j] -= 9;
			}
			sum_even += temp[j];
			sum_odd += (creditcard_no[k] - 48);
		}
		else{
			printf("INVALID creditcard_no\n");
			return 1;
		}
	}
	if((sum_odd + sum_even) % 10 == 0){
		printf("%s is an VALID creditcard_no\n", creditcard_no);
	}
	else{
		printf("%s is an INVALID creditcard_no\n", creditcard_no);
	}

	return 0;
}