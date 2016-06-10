//WAP to store the data of employees and then ask the user to enter current date and list then list all the employees whoes
//ternure os greater than or equal to 3 years
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 5

struct employee{
	unsigned emp_code;
	char name[20];
	unsigned date[3];
}em[MAX] = {
	{12345,"Rajesh",{10,5,2007}},
	{12346,"Suresh",{7,8,2009}},
	{12347,"Dharmesh",{12,4,2006}},
	{12348,"Mahesh",{22,7,2013}},
	{12349,"Sandesh",{1,5,2014}}
};

//declaration of display()
void display(int date[]);
//driver function
int main(void){
	char date2[11];
	char *ptr;
	int len,dt[3]={0},count=0,i=0;

	while(1){
		printf("Enter current date(dd-mm-yyyy):\n");
		printf("Date:\t");
		gets(date2);
		len = strlen(date2);
		if(len < 8 || len > 10){
			printf("INVALID DATE! Enter according to specified format.\n\n");
			continue;
		}
		break;
	}
	ptr = date2;
	
	while(*ptr != '\0'){
		i = 1;
		
		while((*ptr != '-' && len > 0) && count < 3){
			
			if(count == 0){
				dt[0] =  dt[0] * (int)pow(10,i) + (*ptr - 48);
			}
			else if(count == 1){
				dt[1] = dt[1] * (int)pow(10,i) + (*ptr - 48);
			}
			else if(count == 2){
				dt[2] = dt[2] *  (int)pow(10,i) + (*ptr - 48);
			}
			len--;
			ptr++;
		}
		len--;
		ptr++;
		count++;
	}
	count = 1;
	for(i = 0; i < 3; i++){
		switch(i){
			case 0:

				if(dt[0] <= 0 || dt[0] > 31){
					printf("INVALID DATE!\n");
					count = 0;
					break;
				}
				break;
			case 1:
				if(dt[1] <= 0 || dt[1] > 12){
					printf("INVALID DATE!\n");
					count = 0;
					break;
				}
				break;
			case 2:
				if(dt[2] < 1947 || dt[2] > 2050){
					printf("INVALID DATE!\n");
					count = 0;
					break;
				}
				break;
		}
		if(count == 0){
			break;
		}
		
	}
	if(count != 0){
		display(dt);
	}
	printf("\nThnax for using...");
	//while(getchar() != '\n');
	getchar();

	system("clear");

	return 0;
}

//defination of display()
void display(int date[]){
	int i = 0,j = 0;
	int yr = date[2]-3;

	system("clear");
	
	printf("Employees with turnure greater than equal to 3 years:\n\n");
	for(i = 0; i < MAX; i++){
		if(em[i].date[2] < yr){
			j++;
			printf("%d. %s\n",j,em[i].name);
			continue;
		}
		else if(em[i].date[2] == yr){
			if(em[i].date[1] < date[1]){
				j++;
				printf("%d. %s\n",j,em[i].name);
			}
			else {
				if( em[i].date[1] == date[1] && em[i].date[0] <= date[0]){
					j++;
					printf("%d. %s\n",j,em[i].name);
				}
			}
		}
	}
}