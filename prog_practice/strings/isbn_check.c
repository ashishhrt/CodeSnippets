//WAP to verify correctness of ISBN (10-digit number last digit checksum) number of book
//NOTE: Special proberty d1 + 2.d2 + 3.d3......+10.d10 divisible by 11 were di is the ith digit from right

#include<stdio.h>
#include<string.h>
#define LEN 10

int main(void){
	char isbn[11];     //holds isbn number
	int o_checksum,c_checksum,temp;      //holds checksum
	int sum = 0,i;
	int result = 0;       //0 -> incorrect 1 -> correct
	printf("Enter ISBN number:\t");
	scanf("%s",isbn);
	
	if(strlen(isbn) > 10 || strlen(isbn) < 10){
		printf("Invalid ISBN number\n");
		return 1;
	}

	if(isbn[LEN-1] >= 48 && isbn[LEN-1] <= 57){
		o_checksum = (isbn[LEN-1]-48);                 //checksum assigned
	}
	else if(isbn[LEN-1] == 'X'){
		o_checksum = (isbn[LEN-1]-68)/2;
	}
	else{
		printf("Invalid ISBN number\n");
		return 1;
	}
	

	for(i = 0; i < LEN-1;i++){
		if(isbn[i] >= 48 && isbn[i] <= 57){
			temp = (isbn[i] - 48);        // isbn[i]-48  to convert character digits into equivalent numerical digit(ASCII) '4' -> 4
		}
		else{
			printf("Invalid ISBN number\n");
			return 1;
		}

		sum += (10-i)* temp;			//sumation according to rule of checksum but no summing up last digit
	}

	temp = sum % 11;
	if(temp == 0)
		c_checksum = 0;          //Checksum computed
	else{
		c_checksum = 11 - temp;
	}

	if(c_checksum == o_checksum)  //IF computed and orignal checksum same result true i.e 1
		result = 1;
	

	
	if(o_checksum < 10){
		printf("orignal checksum  = %d\n",o_checksum);
	}
	else{
		printf("orignal checksum  = X i.e %d\n",o_checksum);
	}

	if(c_checksum < 10){
		printf("Computed checksum = %d\n",c_checksum);
	}
	else{
		printf("Computed checksum = X i.e %d\n",c_checksum);
	}

	if(result == 0){
		printf("INVALID ISBN number\n");
		return 1;
	}

	printf("VALID ISBN number\n");

	return 0;
}