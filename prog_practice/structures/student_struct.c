//WAP program to store the data of atmost 450 students using structure and
//(A) write a function to print the name of students who joined in a particular year
//(B) write a function to print the data of students whose roll no is received by the function

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50

struct student{
	int roll;
	char name[50];
	char department[20];
	char course[10];
	int year;
}st[MAX];


void menu(void){
	printf("Operations:\n1.Search students joined a particular year\n2.Retrive student details\n3.Register Students\n4.Exit\n");
}
void clear(){
	while(getchar() != '\n' && getchar() != EOF)
		continue;
}

int regi(int *);
void search_year(int upper);
void search_roll(int upper);
//driver function
int main(void){
	int upper = -1,ch = 0;
	//char choice = 'y';

	regi(&upper);

	while(1){
		system("clear");
		menu();
		printf("\nEnter your choice:\t");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				search_year(upper);
				break;
			case 2:
				search_roll(upper);
				break;
			case 3:
				regi(&upper);
				break;
			default:
				ch = 0;
				break;
		}
		if(ch == 0)
			break;
	}

	printf("\nThanx for using...\n");

	return 0;
}

//defination of register() function
int regi(int* z){
	char choice = 'y';
	while(('y' == choice || 'Y' == choice) && *z < MAX-1){
		system("clear");
		*z += 1;
		printf("Enter student details:\n");
		printf("Roll Number\t :\t");
		scanf("%d",&st[*z].roll);
		clear();
		printf("Name\t\t :\t");
		gets(st[*z].name);
		printf("Department\t :\t");
		//clear();
		gets(st[*z].department);
		printf("Course\t\t :\t");
		//clear();
		gets(st[*z].course);
		//clear();
		printf("Enrollment year  :\t");
		scanf("%d",&st[*z].year);
		clear();
		printf("\nYou want to add more students(y/n):\t");
		choice = getchar();
	}
	//return 1;	
}

//defination of search_year() function
void search_year(int upper){
	int year, i = 0,j = 0;
	system("clear");
	while(1){
		printf("Enter year:\t");
		scanf("%d",&year);
		if(year  > 0){
			break;
		}
		else{
			printf("INVALID YEAR, Re-enter\n");
		}
	}
	system("clear");
	printf("\nStudents enrolled in year %d:\n\n",year);
	for(i = 0, j = 0; i <= upper; i++){
		if(st[i].year == year){
			j++;
			printf("%d. %s\n",j,st[i].name);
		}
	}
	if(j == 0){
		system("clear");
		printf("No students enrolled in %d year\n",year);
	}
	printf("\nPress enter...");
	clear();
	getchar();
}

//defination of search_roll() function
void search_roll(int upper){
	int rollno,i = 0;
	system("clear");
	while(1){
		printf("Enter the Roll Number:\t");
		scanf("%d",&rollno);
		if(rollno > 0)
			break;
		else{
			printf("INVALID ROLL NUMBER, Re-enter:\n");
		}
	}

	system("clear");

	for(i = 0; i <= upper; i++){
		if(st[i].roll == rollno){
			printf("\n\nStudent details:\n");
			printf("\nRoll Number\t :\t%d",st[i].roll);
			printf("\nName\t\t :\t%s",st[i].name);
			printf("\nDepartment\t :\t%s",st[i].department);
			printf("\nCourse\t\t :\t%s",st[i].course);
			printf("\nEnrollment Year  :\t%d\n",st[i].year);
			break;
		}
	}
	if(i > upper){
		printf("No student registered with %d roll number.\n",rollno);
	}
	printf("\nPress enter...");
	clear();
	getchar();
}