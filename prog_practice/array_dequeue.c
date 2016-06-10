//WAP to impliment dequeue of characters using array

#include<stdio.h>
#define MAX 10

//function to check space availability in Queue
int space_check(char *left, char *right){
	return right - left;
}

//function to shift elemnts right
void shift_right(char** left, char** right){
	int width = *right - *left;
	
	//printf("width = %d\n",width);
	
	while(width > -1){
		*(*left + (width+1)) = *(*left + width);
		width--;
	}
		*right += 1;
		//printf("**left = %c\t*right = %p\n", **left, *right);
		**left = '\0';
}

//function to shift elements left
void shift_left(char **left, char **right){
	int width = *right - *left;
	int i = 0;
	/*if(width == 0){
		**left = '\0';
	}
	*/
	//else if(width > 0){
		while(i < width){
			*(*left + i) = *(*left +(i+1));
			i++;
		}
		**right = '\0'; 
		*right -= 1;
		//printf("**left = %c\t*right = %p\n", **left, *right);
	//}
	
}

//Function to display the queue elements
void display(char* left, char* right){
		printf("\nQueue elements:\n");
		while(left <= right){
			printf("%c\t",*left);
			left++;
		}
		printf("\n\n");
}

//Driver function
int main(void){
	//const int size = 10;
	char a[MAX];
	//int space_check;
	char retrived_element;
	char *left = &a[0], *right = &a[0];
	unsigned choice = 1;
	int option = 0;
	int count = 0;
	int input_return = 0;
	a[0] = '\0';
	while(choice){
		printf("Option\n1.Left insertion\n2.Right insertion\n3.Left retrival\n4.Right retrival\n5.Quit\nChoice:\t");
		//input_return = scanf("%d",&option);
		while(input_return != 1){
			input_return = scanf("%d",&option);
			if(input_return == 0){
				printf("You entered an invalid option\nRenter Choice:\t");
				while(getchar() != '\n');
			}
		}
		input_return = 0;
		switch(option){
			case 1: 
				if(space_check(left, right) < (MAX - 1) && count == 1){
					shift_right(&left, &right);
					//right++;
					printf("Enter the character to insert\t");
					scanf(" %c",left);
					count = 1;
					display(left, right);
				}
				else if(space_check(left, right) == 0 && count == 0){
					printf("Enter the character to insert\t");
					scanf(" %c",left);
					count = 1;
					display(left, right);
				}
				else{
					printf("\nDequeue is full.To free up space retrive some element first\n");
					display(left, right);
				}
				break;
			case 2:
				if(space_check(left, right) < (MAX - 1) && count == 1){
					//shift_left(a, MAX,left, right);
					
					printf("Enter the character to be inserted:\t");
					scanf(" %c",(right + 1)); 
					right++;
					count = 1;
					display(left, right);
				}
				else if(space_check(left, right) == 0 && count == 0){
					printf("Enter the character to be inserted:\t");
					scanf(" %c",right); 
					count = 1;
					display(left, right);
				}
				else{
					printf("\nDequeue is full. To free up space retrive some element first\n");
					display(left, right);
				}
				break;
			case 3:
				if(space_check(left, right) > 0){
					retrived_element = *left;
					shift_left(&left, &right);
					//right--;
					printf("\nRetrived character  = %c\n",retrived_element);
					display(left, right);
				}
				else if(space_check(left, right) == 0 && count == 1){
					retrived_element = *left;
					printf("\nRetrived character  = %c\n\n",retrived_element);
					*left = '\0';
					count = 0;
					//display(left, right);
				}
				else{
					printf("\nDequeue is empty. To retrive, first insert some elements\n\n");
				}
				break;
			case 4:
				if(space_check(left, right) > 0){
					retrived_element = *right;
					printf("\nRetrived character  = %c\n",retrived_element);
					right--;
					display(left, right);
				}
				else if(space_check(left, right) == 0 && count == 1){
					retrived_element = *right;
					printf("\nRetrived character  = %c\n\n",retrived_element);
					*right = '\0';
					count = 0;
					//display(left, right);
				}
				else{
					printf("\nDequeue is empty. To retrive, first insert some elements\n\n");
				}
				break;
			default:
				printf("You opted to quit\n");
				choice = 0;
				display(left, right);
		}
		
	}
	
	return 0;
}
