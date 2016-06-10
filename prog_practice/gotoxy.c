//WAP to impliment GOTOXY(x,y)

#include<stdio.h>

//gotoxy function
void gotoxy(int x, int y){
	printf("%c[%d;%df",0x1B,y,x);
}
int main(void){
	gotoxy(20,50); //reposition cursor
	printf("Hello reposition cursor!\n");

	return 0;	
} 