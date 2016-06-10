//WAP to impliment linked list and its various operations

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *ptr;	
};

struct node *start,*current,*previous,*ll;

void clear(){
	while(getchar() != '\n');
}

void menu(){
	system("clear");
	printf("Operations available:\n\n");
	printf("1.Add Node\n2.Delete Node\n3.Search an element\n4.Display\n5.Exit\n");
}
//declaration of addNode()
void addNode();
//declaration of display()
int display(int );
//declaration of delNode()
void delNode();
//declaration of search()
void search();

//Driver function
int main(void){
	int ch;
	/*
	start = (struct node *)malloc(sizeof(struct node)); //initializing the linked list
	if(start == NULL){
		printf("Memory full");
		exit(1);
	}
	printf("Enter data:\t");
	scanf("%d",&data);
	start->data = data;
	start->ptr = NULL;
	*/
	while(1){
		menu();
		printf("\nEnter choice:\t");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				addNode();
				break;
			case 2:
				delNode();
				break;
			case 3:
				search();
				break;
			case 4:
				display(0);
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

//defination of addNode()
void addNode(){
	int data,ch,status=0;
	char choice;
	while(1){
		ll = (struct node *)malloc(sizeof(struct node));         //allocating memory for new node
		system("clear");
		if(ll == NULL){
			//system("clear");
			printf("Memory full!\n");
			break;
		}
		printf("Enter data:\t");
		scanf("%d",&data);
		ll->data = data;
		if(start != NULL){
			printf("\nAdd Node at:\n");
			printf("1.Beginning\n2.End\n3.Middle\n");
			printf("\nChoice:\t");
			scanf("%d",&ch);

			switch(ch){
				case 1:
					current = start;    //holding the start node in current
					start = ll;		    //assigning the new node to start
					start -> ptr = current; //pointing new start to prev start(current);
					status = 1;
					break;
				case 2:
					current = start;
					while(current->ptr != NULL){     //traverse to the end
						current = current->ptr;
					}
					current->ptr = ll;   //pointing the current last node to new node
					ll->ptr = NULL;		//Since new node is last node its pointer filed set to NULL
					status = 1;
					break;
				case 3:
					display(1);
					printf("Enter the element after to add new node:\t");
					scanf("%d",&data);
					current = start;
					while(current->data != data && current->ptr != NULL){ //traverse to find the element after to add the new node
						current = current->ptr;
					}
					if(current->ptr == NULL && current->data != data){
						printf("%d is NOT found!\n",data);
						free(ll);
						ll = NULL;
						status = 0;
						break;
					}
					ll->ptr = current->ptr;   //new node points to the node pointed by current
					current->ptr = ll;        //current node now points to new node added
					status = 1;
					break;
				default:
					status = 0;
					break;
			}
		}
		else{
			start = ll;
			start -> ptr = NULL;
			status = 1;
		}
		if(status == 1){
			printf("\nNode added Successfully!\n");
			ll = NULL;
		}
		else{
			printf("\nFAILED to add node!\n");
			free(ll);
			ll = NULL;
		}
		printf("\nDo you want to add more Nodes ?(y/n):\t");
		clear();
		choice = getchar();
		if('y' == choice || 'Y' == choice)
			continue;
		break;
	}
}

//defination of display()
int display(int i){                    //Display the elements in the list
	int count = 0;
	system("clear");
	if(start != NULL){
		current = start;
		printf("Elements in the List:\n\n");
		while(current->ptr != NULL){
			printf("%d\t",current->data);
			current = current->ptr;
			count++;
		}
		printf("%d\n",current->data);
		count++;
	}
	else{
		printf("List is Empty !\n");
	}
	if(i != 1){
		printf("\nPress Enter to continue...");
		clear();
		getchar();
	}

	return count;
}

//defination of delNode
void delNode(){
	int data,status;
	char choice;

	while(1){
		status  = 1;
		system("clear");
		if(display(1)){
			printf("\nEnter the element to delete:\t");
			scanf("%d",&data);

			if(start->ptr != NULL){
				current = start;
				previous = NULL;
				
				while(current->data != data && current->ptr != NULL){
					previous = current;
					current = current->ptr;
				}
				
				if(current->ptr == NULL && current->data != data){
					printf("\n%d is NOT found in list!\n",data);
					status = 0;
				}
				if(current->data == data){
					if(previous != NULL){
						previous->ptr = current->ptr;
					}
					else{
						start = current->ptr;
					}
					free(current);
					current = NULL;
					status = 1;
				}
			}
			else{
				if(start->data != data){
					printf("\n%d is NOT found in list!\n",data);
					status = 0;
				}
				else{
					free(start);
					start = NULL;
					status = 1;
				}
			}

			if(status == 1){
				printf("\nNode Successfully deleted!\n");
			}
			else
				printf("FAILED to delete!\n");

			printf("\nWant to delete more Node?(y/n):\t");
			clear();
			choice = getchar();
			if('y' == choice || 'Y' == choice)
				continue;
			break;
		}
		else{
			printf("\nPress Enter to continue...");
			clear();
			getchar();
			break;
		}
	}
}

//defination of search()
void search(){
	int index = 0,data,status = 1;
	char choice;
	if(start != NULL){
		while(1){
			status = 1;
			index = 0;
			system("clear");
			printf("Enter the Element to search:\t");
			scanf("%d",&data);

			current = start;
			while(current->data != data && current->ptr != NULL){
				index++;
				current = current->ptr;
			}
			if(current->ptr == NULL && current->data != data){
				printf("%d Not found in list!\n",data);
				status = 0;
			}
			if(status != 0){
				printf("%d found in List at index = %d\n",data,index+1);
			}

			printf("\nWant to search another element?(y/n):\t");
			clear();
			choice = getchar();
			if('y' == choice || 'Y' == choice)
				continue;
			else
				break;
		}
	}
	else{
		system("clear");
		printf("List is empty!\n");

		printf("\nPress Enter to continue...");
		clear();
		getchar();
	}
}