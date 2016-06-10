//WAP to receive wind speed and categorize the hurricane
#include<stdio.h>
#define MAX 5

struct hurricane{
	unsigned lwr_limit;
	unsigned upr_limit;
	char category[3];
};

struct hurricane hr[MAX]={             //categories of hurricane on the basis of wind speed
	{74,95,"I"},
	{96,110,"II"},
	{111,130,"III"},
	{131,155,"IV"},
	{156,0,"V"}
};

//Driver function
int main(void){
	unsigned speed;
	int i = 0;

	printf("Enter the speed of wind:\t");
	scanf("%u",&speed);
	
	if(speed < hr[0].lwr_limit){
		printf("\nCalm down its not a hurricane!\n");

	}
	else if(speed >= hr[MAX-1].lwr_limit){
		printf("Hurricane category:\t%s\n",hr[MAX-1].category);
	}
	else{
		for(i = 0; i < MAX; i++){
			if(speed >= hr[i].lwr_limit && speed <= hr[i].upr_limit){
				printf("Hurricane category:\t %s\n",hr[i].category);
				break;
			}
		}
	}

	return 0;
}