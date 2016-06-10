//WAP to find the distance of the last point from the first point(sum of distances between consecutive points)

#include<stdio.h>
#include<math.h>

//Function to calculate the distance between two coordinates
double distance(float a1[], float a2[]){
	int i = 0, j =0;
	double result = 0;
	
	result = sqrt( pow( ( a2[i] - a1[j] ), 2 ) + pow( ( a2[i+1] - a1[j+1] ), 2 ) );
	
	return result;
}

//Driver function
int main(void){
	float a[][2] = {
		{3.0, 1.5},
		{4.5, 2.0},
		{5.5, 3.5},
		{6.5, 5.0},
		{7.5, 6.0},
		{8.5, 7.5},
		{8.0, 9.0},
		{9.0, 10.5},
		{9.5, 12.0},
		{10.0, 14.0}
	};
	
	int size = sizeof(a)/ sizeof(a[0]);
	double result = 0;
	int i = 0;
	
	for(i = 0; i < size - 1; i++){
		result += distance(a[i], a[i+1]);
	}
	
	printf("The distance between the last point from first point  = %.3lf\n",result);
	
	return 0;
}
