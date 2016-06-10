/* To replace a string */

//NOT WORKING
#include<stdio.h>
#include<string.h>

int main(void){
	char str1[20],str2[20];
	char *news,*t, *p;
	int i;

	char *str[] = {
		"We will teach you how to...",
		"Move a mountain",
		"Level a building",
		"Erase the past",
		"Make a million",
		"...all through C!"
	};

	printf("\nEnter the string to be replace: ");
	scanf("%s",str1);
	printf("Enter the new string: ");
	scanf("%s",str2);

	/*check the length of new string*/
	if(strlen(str2) > strlen(str1)){
		printf("Enter a string with %d characters only\n",strlen(str1));
		exit(0);
	}

	for(i = 0; i < 6; i++){          //loop for number of strings
		//Find the entered string in the given array
		p = strstr(str[i],str1);

		if(p){
			//Copy the remaining string
			news = p + strlen(str1);
			strcpy(t, news);
			//Replace the old string
			strcpy(p,str2);
			//Finally append the remaining part
			strcat(p,t);
			break;
		}
	}

	printf("\nThe new string is:\n");
	for(i = 0; i < 6; i++){              //Loop through the strings
		printf("%s\n",str[i]);
	}

	return 0;
}