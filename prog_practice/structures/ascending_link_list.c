//WAP to implement ascending order linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *ptr;	
};

struct node *start,*rear,*current,*previous,*ll;

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
	int data,status=0;
	char choice;
	while(1){
		status = 0;
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
			
			if(data < start->data){
				ll->ptr = start;
				start = ll;
				ll = NULL;
				status = 1;
			}
			else if(rear->data <= data){
				rear->ptr = ll;
				rear = ll;
				rear->ptr = NULL;
				ll = NULL;
				status = 1;
			}
			else{
				previous = start;
				current = start->ptr;

				while(current != NULL){
					if(data < current->data){
						status = 1;
						break;
					}
					previous = current;
					current = current -> ptr;
				}

				if(status == 1){
					previous -> ptr = ll;
					ll->ptr = current;
					previous = NULL;
					current = NULL;
					ll = NULL;
				}
			}
			
		}
		else{
			start = ll;
			start -> ptr = NULL;
			rear = start;
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
		status  = 0;
		system("clear");
		if(display(1)){
			printf("\nEnter the element to delete:\t");
			scanf("%d",&data);

			if(start->ptr != NULL){
				current = start;
				previous = NULL;

				while(current->ptr != NULL){
					if(current -> data == data){
						status = 1;
						break;
					}
					previous = current;
					current = current->ptr;
				}
				if(status == 1){
					if(current != start){
						previous->ptr = current->ptr;
						free(current);
						previous = NULL;
						current = NULL;
					}
					else{
						start = start->ptr;
						free(current);
						current = NULL;
					}
				}
				else if(current == rear && rear->data == data){
					rear = previous;
					previous = NULL;
					free(current);
					current = NULL;
					rear -> ptr = NULL;
					status = 1;
				}
				else{
					printf("\n%d NOT in the list!\n",data);
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