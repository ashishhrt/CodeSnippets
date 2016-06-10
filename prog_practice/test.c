//Test programs

#include<stdio.h>
//#define get(a,b) a##b
//int check(int ,int);

int main(){
	/*int max  = 5;
	float a[max];
	int i;
	float *j;
	j = a;
	j = j + 4;
	
	for(i = 1; i < max; i++){
		//a[i] = i;
		scanf("%f",&a[i]);
	} 
	printf("%p %f %f\n",j,*j,a[4]);
	
	*/
	/*int j,s[5] = {2,4},*ptr;
	ptr = s+2;
	j  = s+2;
	printf("%d %p %d\n", j, ptr, *ptr);
	return 0;
	*/
	
	/*int n[3][3] = {
						2,4,3,
						6,1,5,
						2,3,1
				  };
	printf("%d %d %d\n",**n, *(*n+2),(++**n + --n[1][1]));
	*/
	/*
	static int i = 5;
	if(--i){
		printf("%d\n",i);
		main(10);
	}
	printf("%d\n",get(51,34));
	
	return 0;
	*/

	/*int x, y,z;
	x= 10; y = 40;
	z = check(&x, &y);
	printf("\n%d",z);
	*/
	/*
	int *ptr = NULL;
	printf("pointer = %d",*ptr);
	*/
	/*
	int i = 5, j = 10, k =15;

	printf("%ld\n",sizeof(k /= i+j));
	printf("%d\n",k);
	//printf("nn \n\n nn\n");
	//printf("nn /n/n nn/n");
	*/

	int a[] = {1, 4, 5, 6, 8};
	int *p[] = {a, a+1, a+2, a+3, a+4};
	int i = 0;

	for(i = 0; i < 5; i++){
		printf("p[%d] = %p = %d\n", i, p[i], *p[i]);
	}
	return 0;
}
/*
int check(int x, int y)
int c;
{	c = 10;
	printf("%d %d %d",x,y,c);
	return x + y;
}
*/
