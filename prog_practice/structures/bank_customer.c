//WAP to create a structure for data of customers of a bank
//write a function to print the account number and name of each customers having balance less than Rs.100
//A function for withdrawl and deposite, Message in case of withdrawl leaving amount less than Rs.100

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

struct customer{
	long int accNo;
	char name[40];
	double balance;	
}cust[MAX];

struct opt{              //structure for deposite and withdrawl
	long int accNo;
	double amount;
	short unsigned code; 
}op;

//function for clearing input buffer
void clear(){
	while(getchar() != '\n');
}
//declaration of function addcust() that provides the functionality of adding the customers
int addcust(int *);
//declaration of menu() that list out all the functions offerd by the program
void menu();
//declaration of cust_below100() that list all the customers with balance below 100
void cust_below100(int );
//declaration of deposite() that will provide the functionality of money deposite
void deposite(int );
//declaration of withdrawl() that will provide the functionality of money withdrawl
void withdrawl(int);

//Driver function
int main(void){
	int upper = -1,choice;
	
	//add  new customer
	addcust(&upper);

	while(1){
		menu();
		printf("\nEnter your choice:\t");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				addcust(&upper);
				break;
			case 2:
				cust_below100(upper);
				break;
			case 3:
				deposite(upper);
				break;
			case 4:
				withdrawl(upper);
				break;
			default:
				choice = 0;
				break;
		}

		if(choice == 0)
			break;
	}

	printf("\nThanx for using...");
	clear();
	getchar();
	system("clear");
	return 0;
}

//defination of menu() function
void menu(){
	system("clear");
	printf("Choose options:\n\n");
	printf("1. Add New customer\n");
	printf("2. Customers (balance below Rs.100)\n");
	printf("3. Deposite\n");
	printf("4. Withdrawl\n");
	printf("5. Exit\n");
}

//defination of addcust() function
int addcust(int *upper){
	char ch;
	while(1){
		system("clear");
		*upper += 1;
		printf("Enter Cutomer Details:\n");
		printf("\nAccount Number:\t");
		scanf("%ld",&cust[*upper].accNo);
		printf("Customer Name:\t");
		clear();
		gets(cust[*upper].name);
		printf("Initial Balance:  ");
		scanf("%lf",&cust[*upper].balance);

		printf("\nDo you want to add More customers ?(y/n):\t");
		clear();
		ch = getchar();
		if(ch == 'y' || ch == 'Y')
			continue;
		else
			break;
	}
	return 0;
}

//defination of cust_below100() function
void cust_below100(int upper){
	system("clear");
	int j = 0,i = 0;
	printf("Customers with balance below Rs.100:\n\n S.No\tAccount Number\t   Name\n\n");
	while(i <= upper){
		if(cust[i].balance < 100){
			j++;
			printf("   %d.  \t%ld\t\t   %s \n",j,cust[i].accNo,cust[i].name);
		}
		i++;
	}
	if(j == 0){
		system("clear");
		printf("Every customer have balance above threshold!\n");
	}

	printf("\nPress Enter to continue...");
	clear();
	getchar();
}

//defination of deposite() function
void deposite(int upper){
	int i = 0,counter = 0;
	op.code = 1;
	system("clear");
	printf("Deposite details:\n\n");
	printf("Account Number:\t");
	scanf("%ld",&op.accNo);
	while(1){
		printf("Amount:\t");
		scanf("%lf",&op.amount);

		if(op.amount <= 0){
			printf("\nINVALID Amount!\nRe-enter ");
			continue;
		}
		break;
	}

	while(i <= upper){
		if(cust[i].accNo == op.accNo){
			cust[i].balance += op.amount;
			counter = 1;
			break;
		}
		i++;
	}

	system("clear");
	if( 0 == counter){
		printf("INVALID Account Details\n");
	}
	else{
		printf("Account Succesfully updated!\n\n");
		printf("Account Number:\t%ld\n",cust[i].accNo);
		printf("New Balance:\t%.2lf\n",cust[i].balance);
	}

	printf("\nPress Enter to continue...");
	clear();
	getchar();	
}

//defination of withdrawl() function
void withdrawl(int upper){
	int i = 0, counter = 0;
	double temp;
	op.code = 0;

	system("clear");

	printf("Withdrawl Details:\n\n");
	printf("Account Number:\t");
	scanf("%ld",&op.accNo);
	
	while(1){
		printf("Amount:\t");
		scanf("%lf",&op.amount);

		if(op.amount <= 0){
			printf("\nINVALID Amount!\nRe-enter ");
			continue;
		}
		break;
	}

	while(i <= upper){
		if(cust[i].accNo == op.accNo){
			temp = cust[i].balance;
			cust[i].balance -= op.amount;
			if(cust[i].balance < 100){
				cust[i].balance = temp;
				temp = 0.0;
				counter = 2;
				break;
			}
			temp = 0.0;
			counter = 1;
			break;
		}
		i++;
	}

	system("clear");
	if(counter == 1){
		printf("Withdrawl Succesful!\n\n");
		printf("Account Number:\t%ld\n",cust[i].accNo);
		printf("New Balance:\t%.2lf\n",cust[i].balance);
	}
	else if(counter == 2){
		printf("Withdrawl FAILED! \nThe balance is insuffcient  for the specified withdrawl\n\n");
		printf("Account Number:\t%ld\n",cust[i].accNo);
		printf("Balance:\t%.2lf\n",cust[i].balance);
		printf("Expected amount after withdrawl:\t%.2lf\n",cust[i].balance - op.amount);
		printf("Balance not allowed below Rs.100\n");
	}
	else{
		printf("INVALID Account Details!\n");
	}

	printf("\nPress Enter to continue...");
	clear();
	getchar();
}