//WAP of event driven library management system

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

struct library{
	unsigned accNo;
	char t_book[30];
	char a_name[20];
	double price;
	unsigned flag;      // 0 issued,1 avialble
}lib[MAX];

void clear(){
	while(getchar() != '\n');
}

void menu(){
	system("clear");
	printf("Options:\n\n");
	printf("1. Add book information\n2. Display book information\n3. List all the books of given author\n");
	printf("4. List the title of specified book\n5. List the count of books in the library\n");
	printf("6.List the books in the order of accession number\n7.Exit\n");
}

int check_accNo(int accNo,int upper){
	int i = 0,check = 0;

	if(accNo < 0 || accNo > 9999){
		return 1;         //Invalid accNo
	}
	else if(upper < 0){
		return 2;         //database empty
	}
	else {
		for(i = 0; i <= upper; i++){
			if(accNo == lib[i].accNo)
				check++;
		}
		if(check != 0){
			return 3;     //given accNo present in database
		}
	}
	return 0;      //valid but not present in database
}

//declaration of comp()
int comp(const void *, const void *);
//declaration of add_book()
void add_book(int *);
//declaration of disp_book
void disp_book(int );
//declaration of disp_auth_book()
void disp_auth_book(int );
//declaration of disp_title_book()
void disp_title_book(int );
//declaration of disp_books_acc_order()
void disp_books_acc_order(int );

//Driver function
int main(void){
	int upper = -1;
	int ch;
	
	while(1){
		menu();

		printf("\nEnter your choice:\t");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				add_book(&upper);
				break;
			case 2:
				disp_book(upper);
				break;
			case 3:
				disp_auth_book(upper);
				break;
			case 4:
				disp_title_book(upper);
				break;
			case 5:
				system("clear");
				printf("Total books present in the library = %d\n",upper+1);
				printf("\nPress Enter to continue...");
				clear();
				getchar();
				break;
			case 6:
				disp_books_acc_order(upper);
				break;
			default:
				ch = 0;
				break;
		}

		if(ch == 0)
			break;
	}

	printf("\nThanks for using...");
	clear();
	getchar();
	system("clear");

	return 0;
}

//defination of add_book()
void add_book(int *upper){
	char ch;
	int check = 0,i,temp_upper;
	unsigned accNo,flag;

	while(1){
		*upper += 1;
		temp_upper = *upper;
		system("clear");
		printf("Enter book details:\n\n");

		while(1){
			printf("Accession Number:\t");
			scanf("%u",&accNo);

			switch(check_accNo(accNo, *upper)){
				case 1:
					printf("INVALID Accession Number!\n\n");
					printf("Re-Enter ");
					check = 1;
					break;	
				case 2:
					printf("Library is Empty!\n\n");
					check = 0;
					break;
				case 3:
					printf("Book alredy present!\n\n");
					for(i = 0; i <= *upper; i++){
						if(accNo == lib[i].accNo)
							break;
					}
					flag = lib[i].flag;
					printf("%d. Accession No: %u\tTitle: %s\tAuthor: %s\tPrice: %.2lf\tStatus: %s\n",i+1,lib[i].accNo,lib[i].t_book,lib[i].a_name,lib[i].price,((flag == 0)?"Issued":"Available"));
					printf("\nDo you want to Edit the details?(y/n):\t");
					clear();
					ch = getchar();
					if('y' == ch || 'Y' == ch)
						check = 2;
					else
						check = 3;
					break;
				default:
					check = 0;
					break;
			}
			if(check == 1)
				continue;
			else if(check == 2){
				temp_upper = i;
				*upper -= 1;
				break;
			}
			else if(check == 3){
				*upper -= 1;
				break;
			}
			else{
				lib[temp_upper].accNo = accNo;
				break;
			}
		}
		if(check == 3){
			goto x;
		}
		printf("Title:\t");
		clear();
		gets(lib[temp_upper].t_book);
		printf("Author:\t");
		//clear();
		gets(lib[temp_upper].a_name);
		printf("Price:\t");
		scanf("%lf",&lib[temp_upper].price);
		printf("(0-> issued, 1 - > available)\n");
		while(1){
			printf("Status:\t");
			scanf("%u",&lib[temp_upper].flag);
			if(lib[temp_upper].flag != 0 && lib[temp_upper].flag != 1){
				printf("INVALID Status!\n");
				printf("Re-Enter ");
				continue;
			}
			break;
		}
	 x:
		printf("\nMore books to add?(y/n):\t");
		clear();
		ch = getchar();
		if('y' == ch || 'Y' == ch){
			clear();
			continue;
		}
		break;
	}
}

//defination of disp_book()
void disp_book(int upper){
	int i = 0;
	unsigned flag;
	system("clear");
	if(upper > -1){
		printf("List of books in the library:\n\n");

		for(i = 0; i <= upper; i++){
			flag = lib[i].flag;
			printf("%d. Accession No: %u\tTitle: %s\tAuthor: %s\tPrice: %.2lf\tStatus: %s\n",i+1,lib[i].accNo,lib[i].t_book,lib[i].a_name,lib[i].price,((flag == 0)?"Issued":"Available"));
		}
	}
	else{
		printf("Library is Empty!\n");
	}
	printf("\nPress Enter to continue...");
	clear();
	getchar();
}

//defination of disp_auth_book()
void disp_auth_book(int upper){
	char auth[20];
	int i = 0,j = 0,cmp;

	while(1){
		system("clear");
		printf("Enter author name:\t");
		clear();
		gets(auth);

		printf("List of Books written by %s:\n\n",auth);
		for(i = 0; i <= upper; i++){
			cmp = strcasecmp(lib[i].a_name, auth);
			if(cmp == 0){
				j++;
				printf("%d. %s\n",j,lib[i].t_book);
			}
		}
		if(j == 0){
			system("clear");
			printf("No books found in the library of author %s\n",auth);
			j = 0;
		}
		break;
	}
	printf("\nPress Enter to continue...");
	//clear();
	getchar();
}	

//defination of disp_title_book()
void disp_title_book(int upper){
	unsigned accNo;
	int i = 0,check = 0;
	system("clear");
	while(1){
			printf("Accession Number:\t");
			scanf("%u",&accNo);

			switch(check_accNo(accNo, upper)){
				case 0:
					printf("%d is not found in the database!\n\n",accNo);
					printf("Re-Enter ");
					check = 1;
					break;
				case 1:
					printf("INVALID Accession Number!\n\n");
					printf("Re-Enter ");
					check = 1;
					break;
				case 2:
					printf("Library is Empty!\n\n");
					check = 2;
					break;
				default:
					check = 0;
					break;
			}
			if(check == 1)
				continue;
			
			break;
		}

	if(check == 0){
		
		for(i = 0; i <= upper; i++){
			if(accNo == lib[i].accNo){
				printf("\nTitle:\t%s\n",lib[i].t_book);
				break;
			}
		}
	}
	
	printf("\nPress Enter to continue...");
	clear();
	getchar();
}

//declaration of disp_books_acc_order(upper)
void disp_books_acc_order(int upper){
	int i = 0;
	system("clear");
	if(upper < 0){
		printf("Library is Empty!\n\n");
	}
	else{
		qsort((struct library *)lib, upper+1, sizeof(lib[0]), comp);

		printf("List of books in the library:\n\n");
		for(i = 0; i <= upper; i++){
		printf("%d. Accession No: %u\tTitle: %s\tAuthor: %s\tPrice: %.2lf\tStatus: %s\n",i+1,lib[i].accNo,lib[i].t_book,lib[i].a_name,lib[i].price,(0?"Issued":"Available"));
		}
	}
	printf("\nPress Enter to continue...");
	clear();
	getchar();
}

//defiantion of comp()
int comp(const void *p1, const void *p2){
	return(((struct library *)p1)->accNo - ((struct library *)p2)->accNo);
}