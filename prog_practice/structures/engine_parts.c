//WAP to create a structure for engine parts having serial number starting from AA0 to FF9
//Write a function to retrieve info on parts with serial numbers between BB1 to CC6

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 360

struct engp{
	char serial[4];
	unsigned yofm;
	char material[20];
	unsigned quantity;
}parts[MAX];

void clear(void){
	while(getchar() != '\n');
}

void menu(void){
	system("clear");
	printf("Options:\n\n");
	printf("1.Enter details of a product\n2.Display product details from BB1 to CC6\n3.Exit\n");
}
//declaration of regi_serial() function
void regi_serial(void);
//declaration of prod_details() function
void prod_details(void);
//declaration of display() function
void display(void);

//Driver function
int main(void){
	int ch = 0;
	
	regi_serial();	//registering serials of product

	prod_details(); // enter details of a part
	
	while(1){
		menu();
		printf("\nEnter choice:\t");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				prod_details();
				break;
			case 2:
				display();
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

//defination display() function
void display(void){
	int i = 0, j = 0, k = 0;
	system("clear");
	for(i = 0; i < MAX; i++){
		if(strcmp(parts[i].serial,"BB1") == 0){
			k = i;
			j = 1;
		}
		if(j > 0)
			j++;
		if(strcmp(parts[i].serial,"CC6") == 0)
			break;
	}
	printf("Product details from BB1 to CC6:\n\n");
	printf("S.No   YOFM\tMaterial\tQuantity\n\n");
	for(i = k; i < j + k-1; i++){
		printf("%s\t%u\t%s \t\t%u\n",parts[i].serial,parts[i].yofm,parts[i].material,parts[i].quantity);
	}

	printf("\n\nPress Enter to continue...");
	clear();
	getchar();
}

//defination of prod_details() function
void prod_details(void){
	int i = 0, ch = -1;
	char serial[4];
	char choice;

	while(1){
		system("clear");
		ch = -1;
		printf("Product details:\n\n");
		
		while(1){

			printf("Serial(AA0 t0 FF9):\t");
			//clear();
			gets(serial);
			if(strlen(serial) > 3 || strlen(serial) < 3){
				printf("INVALID PRODUCT SERIAL\n");
				printf("Re-enter ");
				continue;
			}
			i = 0;
			while(i < 2){
				
				if(serial[i] >= 97 && serial[i] <= 122){
					serial[i] -= 32;
				}
				i++;
			}
			for(i = 0; i < MAX; i++){
				if(strcmp(serial,parts[i].serial) == 0){
					strcpy(parts[i].serial,serial);
					ch = i;
					break;
				}
			}
			if( ch > -1){
				break;
			}
			else{
				printf("INVALID PRODUCT SERIAL\n");
				printf("Re-enter ");
			}
		}

		printf("Year of manufacture:\t");
		scanf("%u",&parts[ch].yofm);
		//clear();
		printf("Material:\t");
		clear();
		gets(parts[ch].material);
		printf("Quantity:\t");
		scanf("%u",&parts[ch].quantity);
		//clear();

		printf("\nDo you want to enter details of more product(y/n):\t");
		clear();
		choice = getchar();
		clear();
		if('y' == choice || 'Y' == choice)
			continue;
		else
			break;
	}
}

//defination of regi_serial() function
void regi_serial(void){
	int i = 0,j = 0,m = 0,index = 0;
	char *ptr;
	char k[][10] = {{"0"},{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"}};

	//Registering the model numbers
	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			for(m = 0; m < 10; m++){
				//printf("inside k = %s\n",k[m]);
				switch(i){
					//printf("inside 1st switch\n");
					case 0:
						switch(j){
							//printf("inside 2nd switch\n");
							case 0:
								ptr = "AA";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								//printf("%s\n",parts[index-1].serial);
								break;
							case 1:
								ptr = "AB";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 2:
								ptr = "AC";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 3:
								ptr = "AD";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 4:
								ptr = "AE";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 5:
								ptr = "AF";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
						}
						break;
					case 1:
						switch(j){
							case 0:
								ptr = "BA";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 1:
								ptr = "BB";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 2:
								ptr = "BC";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 3:
								ptr = "BD";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 4:
								ptr = "BE";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 5:
								ptr = "BF";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
						}
						break;
					case 2:
						switch(j){
							case 0:
								ptr = "CA";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 1:
								ptr = "CB";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 2:
								ptr = "CC";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 3:
								ptr = "CD";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 4:
								ptr = "CE";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 5:
								ptr = "CF";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
						}
						break;
					case 3:
						switch(j){
							case 0:
								ptr = "DA";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 1:
								ptr = "DB";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 2:
								ptr = "DC";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 3:
								ptr = "DD";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 4:
								ptr = "DE";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 5:
								ptr = "DF";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
						}
						break;
					case 4:
						switch(j){
							case 0:
								ptr = "EA";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 1:
								ptr = "EB";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 2:
								ptr = "EC";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 3:
								ptr = "ED";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 4:
								ptr = "EE";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 5:
								ptr = "EF";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
						}
						break;
					case 5:
						switch(j){
							case 0:
								ptr = "FA";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 1:
								ptr = "FB";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 2:
								ptr = "FC";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 3:
								ptr = "FD";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 4:
								ptr = "FE";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
							case 5:
								ptr = "FF";
								
								strcpy(parts[index].serial,ptr);
								strcat(parts[index].serial,*(k+m));
								index += 1;
								break;
						}
						break;
					default:
						break;
				}
			}
		}
	}
}