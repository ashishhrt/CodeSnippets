//WAP for inventory management
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DIV 3
#define PRODUCT 4
#define COMP 3

//Driver function
int main(void){
	int *inventory[DIV][PRODUCT];     //3 divisions, 4 products
	int *c;
	int cost[] = {100,200,300,400};     //Cost of per item of inventory
	int comp_no;
	int div_no;
	//short int prod_no[PRODUCT];
	int order[PRODUCT] = {0,0,0,0};
	int long total_amount = 0l;
	int i, j,k;
	char choice = 'y',ch;

	for(i = 0; i < DIV; i++){
		for(j = 0; j < PRODUCT; j++){
			c = (int *)malloc(sizeof(int) * 3);
			inventory[i][j] = c;
			*(inventory[i][j] + 0) = 0;
			*(inventory[i][j] + 1) = 0;
			*(inventory[i][j] + 2) = 0;
		}
	}
	while(choice == 'y' || choice == 'Y'){
		system("clear");
		printf("Enter the division number:\t");
		scanf("%d",&div_no);
		if(div_no < 1 || div_no > 4){
			printf("INVALID Division number\n");
			continue;
		}
		printf("Enter the company number:\t");
		scanf("%d",&comp_no);
		if(comp_no < 1 || comp_no > 3){
			printf("INVALID Comapny number\n");
			continue;
		}
		for(i = 0; i < PRODUCT; i++){
			printf("Enter the Product number:\t");
			scanf("%d",&j);
			if(j < 1 || j > 4){
				printf("INVALID Product number\n");
				i -= 1;
				continue;
			}

			if( order[j-1] != 0){
				printf("Product already registered, please choose different product\n");
				i -= 1;
				continue;
			}

			printf("Enter the number of Products ordered:\t");
			scanf("%d",&order[j-1]);
			while(getchar() != '\n');
			if( i < 3){
				printf("you want more products to register ?(y/n):\t");
				ch = getchar();
				while(getchar() != '\n');
				
				if(ch != 'y' && ch != 'Y')
					break;
			}
		}
		for(i = 0; i < PRODUCT; i++){
			*(inventory[div_no-1][i]+(comp_no-1)) += order[i];
			order[i] = 0;
		}
		printf("You want more orders to register?(y/n):\t");
		//while(getchar() != '\n' || getchar() != EOF);
		choice = getchar();
	}
	system("clear");
	printf("Inventory details:\n\n");
	printf("Product:\t1\t2\t3\t4\n");
	printf("--------------------------------------------------");
	for( i = 0; i < DIV; i++){
		printf("\nDivision %d:",i+1);
		for(j = 0; j < PRODUCT; j++){
			k = (*(inventory[i][j] + 0) + *(inventory[i][j] + 1) + *(inventory[i][j] + 2));
			printf("\t%d",k);
		}
	}
	printf("\n\nTotal cost of each product present in each division:\n\n");
	printf("Product:\t1\t2\t3\t4\n");
	printf("--------------------------------------------------");
	for( i = 0; i < DIV; i++){
		printf("\nDivision %d:",i+1);
		for(j = 0; j < PRODUCT; j++){
			k = (*(inventory[i][j] + 0) + *(inventory[i][j] + 1) + *(inventory[i][j] + 2)) * cost[j];
			printf("\t%d",k);
			total_amount += k; 
		}
	}
	printf("\n\nTOTAL AMOUNT = %3ld\n",total_amount);

	return 0;
}