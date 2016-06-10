//WAP that converts string like '1234' into integer 1234

#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void){
	char str[10];
	int n = 0,i = 0,len;

	printf("Enetr a numerical string:\t");
	scanf("%s",str);
	len = strlen(str);
	
	while(str[i] != '\0' && len > 0){
		
		//p = pow(10, --len);
		//printf("%d %d %d %d %c\n",i ,n, len, p,str[i]);
		if(str[i] >= 48 && str[i] <=57){
			n = n + (str[i]-48)* pow(10, --len);
			i++;
		}
		else{
			printf("Invalid numerical string input\n");
			return 1;
		}
		
	}

	printf("Numerical conversion of '%s' is %d\n",str,n);

	return 0;
}