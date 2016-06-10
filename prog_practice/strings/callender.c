//WAP to input a month and a year and print the callender of that corresponding month and year
//NOTE: according to Gregorian calendar 01/01/1900 was Monday (any centuary not divisible by 400 is not considered as leap centuary)
//E.g: 1700,1800,1900 are not leap years although divisible by 4

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define YEAR 1900

/*-----defination of gotoxy Function------*/
void gotoxy(short int x,short int y){
	printf("%c[%d;%df",0x1B,y,x);
}
/*----declaration of drawBox function-----*/
void drawBox();
/*-----declaration of functions used------*/
int find_month(char* );
int long find_days(int ,int);
void display(int, int, int);
char days[][10] = {
	"Sun",
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat"
};
char *month[] = {
		"JANUARY",
		"FEBRUARY",
		"MARCH",
		"APRIL",
		"MAY",
		"JUNE",
		"JULY",
		"AUGUST",
		"SEPTEMBER",
		"OCTOBER",
		"NOVEMBER",
		"DECEMBER"
	};
int c_month_days;
/*---Driver function------*/
int main(void){
	char month[10],choice;
	int c_year,c_month,day,i;
	long int total_days;

	system("clear");
	printf("Enter the details (Year greater than 1900):\n");
	printf("Year: ");
	scanf("%d",&c_year);
	if(c_year < 1900 || c_year > 3000){
		printf("INVALID INPUT\n");
		return 1;
	}
	printf("Month: ");
	scanf("%s",month);

	for(i = 0; i < strlen(month); i++){
		if(month[i] >= 65 && month[i] <= 90)
			continue;
		else if (month[i] >= 97 && month[i] <= 122)
		{
			month[i] = month[i] - 32; //Converts into Upper Case
		}
		else{
			printf("INVALID INPUT\n");
			return 1;
		}
	}
	c_month = find_month(month);                         //c_month is current month
	if(c_month == 55){
		printf("INVALID INPUT\n");
		return 1;
	}
	total_days = find_days(c_year, c_month);			 //find the total days since 1900
	day = total_days % 7;			//find the day of last day of previous month 0. Sunday 1. Monday 2. Tuesday...6. Saturday

	display(day,c_month,c_year);
	i = 1;
	while(i){
		while((choice = getchar()) != '\n' && choice != EOF);
		printf("Options:\n1.Press 'a' to see previous month\n2.Press 'd' to see next month\n3.Press 'w' to see same month of previous year\n4.Press 's' to see same month of next year\n5.Press 'q' to quit\nChoice:\t");
		choice = getchar();

		switch(choice){
			case 65:
			case 97: 
			if(c_month > 1){
				c_month -= 1;
			}
			else{
				c_month = 12;
				c_year -= 1;
				if(c_year < 1900){
					i = 0;
					break;
				}
			}
			total_days = find_days(c_year,c_month);
			day = total_days % 7;
			display(day,c_month,c_year);
			break;

			case 68:
			case 100:
			if(c_month < 12){
				c_month += 1;
			}
			else{
				c_month = 1;
				c_year += 1;
			}
			break;

			case 87:
			case 119:
			if(c_year > 1900){
				c_year -= 1;
			}
			else{
				printf("Calender not available before 1900\n");
				i = 0;
				while(getchar() != '\n');
				getchar();
			}
			break;

			case 83:
			case 115:
			if(c_year < 3000)
				c_year += 1;
			else{
				printf("Calender not available after 3000\n");
				i = 0;
				while(getchar() != '\n');
				getchar();	
			}
			break;

			default:
				i = 0;
				break;
		}

		if(i != 0){
			total_days = find_days(c_year,c_month);
			day = total_days % 7;
			display(day,c_month,c_year);
		}
	}
	system("clear");
	return 0;
}

/*---Defination of find_month() function---*/
int find_month(char *c_month){
	
	int mon,i,cmp;
	for(i = 0; i < 12;i++){
		cmp = strcmp(c_month,month[i]); 
		if(cmp == 0){
			mon = i+1;
			break;
		}
	}
	if(cmp != 0){
		mon = 55;
	}

	return mon;
}
/*----Defination of find_days() function----*/
long int find_days(int c_year,int c_month){
	long int days = 0l;
	int i,year,leap_yr=0;

	year = c_year - YEAR;
	for(i = YEAR+4; i < c_year; i+=4){
		leap_yr++;                 //Counting leap years
	}
	days = (year*365) + leap_yr;
	if(c_month > 1){
		for(i = 1; i < c_month; i++){
			int rem = i%2;
			if(rem != 0){
				if(i < 8)
					days += 31;
				else
					days += 30;
			}
			else if (rem == 0){
				if(i < 7){
					if( i != 2)
						days += 30;
					else{
						if(c_year % 4 == 0 && c_year != YEAR)
							days += 29;
						else
							days += 28;
					}
				}
				else{
					days += 31;
				}
			}
		}
	}

	return days;
}
/*-----Defination of drawBox function------*/
void drawBox(){
	int i;
	gotoxy(25,17);
	printf("-------------------------------------------------------");
	for(i = 0; i < 10; i++){
		gotoxy(25,18+i);
		printf("|");		
		gotoxy(79,18+i);
		printf("|");
	}
	gotoxy(25,27);
	printf("-------------------------------------------------------");
	//gotoxy()
}

/*----Defination of display() function-----*/
void display(int day, int c_month, int c_year){
	int i,j,k=0,c_days,rem;
	/*
	for(i = 0; i < 10; i++){
		printf("    ");
	}
	*/
	system("clear");//clear screen
	gotoxy(43,15);
	printf("%c  %s  %d  %c\n\n",60,month[c_month-1],c_year,62);
	//printf("                     ");
	/*----Draw Box---*/
	drawBox();
	i = 0;
	gotoxy(27,19);
	while(i < 7){
		printf("%s\t",days[i]);
		//printf("\t");
		i++;
	}

	rem = c_month % 2;
	if(rem!= 0)
		if(c_month < 8)
			c_days = 31;
		else
			c_days = 30;
	else if(rem == 0){
		if(c_month == 2){
			if((c_year % 4 == 0 && c_year != YEAR))
				c_days = 29;
			else
				c_days = 28;
		}
		else {
			if(c_month < 7)
				c_days = 30;
			else
				c_days = 31;
		}
	}
	day++;
	printf("\n");

	for(i = 1; i <= c_days;){
		gotoxy(27,21+k);
		for(j = 0; j < 7; j++){
			if(i > c_days)
				break;
			if(j != day){
				printf("   \t");
				continue;
			}
			printf("%3d\t",i);
			day++;
			i++;
		}
		day = 0;
		k++;
	}
	fflush(stdout);
	gotoxy(0,0);
}