//WAP that compares two dates

#include<stdio.h>
#define MAX 2

struct date{
	unsigned day;
	unsigned month;
	unsigned year;	
}dt[MAX];

//declaration of cmp_dates()
int cmp_date();
//declaration of check_date();
int check_date(struct date);

//Driver function
int main(void){
	int count = 0;

	while(count < 2){
		printf("Enter date%d(dd mm yyyy):\t",count+1);
		scanf("%u %u %u",&dt[count].day,&dt[count].month,&dt[count].year);
		if(check_date(dt[count])){
			printf("INVALID DATE!\n\n");
			printf("Re-");
			//count--;
			continue;
		}
		count++;
	}

	if(cmp_date()){
		return 0;   //when both dates are equal
	}
	else
		return 1;	//when both dates are not equal
}

//defination of check_date()
int check_date(struct date d){
	int count = 0;
	if(d.day > 0 && d.day < 32)
		count++;
	if(d.month > 0 && d.month < 13)
		count++;
	if(d.year > 999 && d.year < 10000)
		count++;

	if(count == 3)
		return 0;  //valid date
	else
		return 1; //Invalid date
}

//defination of cmp_date()
int cmp_date(){
	int count = 0;
	if(dt[0].day == dt[1].day)
		count++;
	if(dt[0].month == dt[1].month)
		count++;
	if(dt[0].year == dt[1].year)
		count++;

	if(count == 3){
		printf("\nDates Equal!\n");
		return 1; 
	}
	else{
		printf("\nDates are not equal!\n");
		return 0;
	}
}	