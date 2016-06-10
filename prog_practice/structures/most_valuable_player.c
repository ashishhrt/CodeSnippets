//WAP to implement the MVP scheme
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct player{
	int playr;
	unsigned judge1;
	unsigned judge2;
	unsigned judge3;
	unsigned sum;
}pl[MAX];

//comparison function for sorting
int cmp(const void *p1, const void *p2){
	return (((struct player *)p1)->sum - ((struct player *)p2)->sum);
}
//Driver function
int main(void){
	int i = 0;

	for(i = 0; i < MAX; i++){
		system("clear");
		printf("Enter ranking for Player %d:\n",i+1);
		printf("judge 1:\t");
		scanf("%d",&pl[i].judge1);
		printf("judge 2:\t");
		scanf("%d",&pl[i].judge2);
		printf("judge 3:\t");
		scanf("%d",&pl[i].judge3);
		pl[i].playr = i+1;
		pl[i].sum = pl[i].judge1 + pl[i].judge2 + pl[i].judge3;
	}
	//sorting the players
	qsort((struct player *)pl, MAX, sizeof(pl[0]),cmp);

	printf("\n\nMOST VALUABLE PLAYER IS PLAYER %d\n\n",pl[MAX-1].playr);

	return 0;
}