//TEST program
#include<stdio.h>

int main(void){
	char text;
	int a,b;
	//scanf("%d",&c);
	//printf("%d %c\n",c,c);
	scanf("%d%*c%d%*c%c",&a,&b,&text);
	printf("%d\t%d\t%c\n",a,b,text);
	return 0;
}