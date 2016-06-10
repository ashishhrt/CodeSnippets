//Test string program
#include<stdio.h>
#include<string.h>

int main(void){
	char str[6]= "ashish";
	//char str2[] = {'A','B','c','D'};
	char *p;
	int i = 0;

	for(i = 0; i < 6; i++)
		printf("%d\t",*	str);
	p = str+1;
	printf("\n%p\n",p);
	//p = strcat(str, str2);

	//*(p+1) = 'K';   //works good
	//printf("%s\n",p);
	/*
	while( str[i] != 0){
		printf("%c\t",i[str]);
		i++;
	}
	printf("\n%d %d %d\n",sizeof('3'), sizeof("3"), sizeof(3));
	printf("%c\n","abcdefg"[4]);
	*/
	return 0;
}