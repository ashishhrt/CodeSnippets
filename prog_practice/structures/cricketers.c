//WAP to store the data of 20 cricketers 
//sort them in ascending order according to their test averrage

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

struct cricket{
	char name[30];
	unsigned age;
	unsigned test;
	double avg;
}player[MAX];

void clear(){
	while(getchar() != '\n');
}
//declaration of addPlayer()
void addPlayer(int *);

//defination of menu()
void menu(){
	system("clear");
	printf("Options:\n\n");
	printf("1. Add player(MAX 20)\n2. List player\n3. Exit\n");
}

//declaration of display()
void display(int *);

//declaration of comp()
int comp(const void *p1, const void *p2);

//Driver function
int main(void){
	int upper = -1,ch = 0;
	
	addPlayer(&upper);   //add player

	while(1){
		menu();
		printf("\nEnter your choice:\t");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				addPlayer(&upper);
				break;
			case 2:
				display(&upper);
				break;
			default:
				ch = 0;
				break;
		}
		if(ch == 0)
			break;
	}
	
	printf("\n\nThanks for using...");
	clear();
	getchar();
	system("clear");

	return 0;	
}

//defination of addPlayer()
void addPlayer(int *upper){
	//int i = 0;
	char ch;

	while(1){
		system("clear");
		*upper += 1;
		printf("Player Details:\n\n");
		printf("Name:\t");
		gets(player[*upper].name);
		printf("Age:\t");
		scanf("%u",&player[*upper].age);
		printf("Test:\t");
		scanf("%u",&player[*upper].test);
		printf("Average:  ");
		scanf("%lf",&player[*upper].avg);


		printf("\nDo you want to add more players(MAX 20)? (y/n):\t");
		clear();
		ch = getchar();

		if(('y' == ch || 'Y' == ch) && *upper < 19){
			clear();
			continue;
		}
		else
			break;
	}
}
//defination of comp()
int comp(const void *p1, const void *p2){
	
	return (((struct cricket *) p1)->avg - ((struct cricket *) p2)->avg);
}
//Defination of display()
void display(int *upper){
	int i = 0;
	qsort((struct cricket *)player, *upper+1, sizeof(player[0]),comp);
	system("clear");

	printf("S.No  Name\t\tAge  Test Matches  Average Runs\n\n");

	for(i = 0; i <= *upper; i++){
		printf("%2d  %s\t%2u\t %3u\t\t %.2lf\n",i+1,player[i].name,player[i].age,player[i].test,player[i].avg);
	}

	printf("\n\nPress Enter to continue...");
	clear();
	getchar();
}