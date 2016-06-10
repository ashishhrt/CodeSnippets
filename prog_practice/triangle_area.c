//WAP to find the area of triangle using the sine rule and find the max among the all
#include<stdio.h>
#include<math.h>

//function to finad area of triangle
double find_area(double a[]){
	double sign = sin(a[2]);
	double area;
	area = (a[0] * a[1] * sign)/2;
	//printf("area = %.3lf\t sin = %.3lf\ta[0] = %.3lf\t a[1] = %.3lf\n", area, sign, a[0], a[1]);
	return area;
}
//Driver function
int main(void){
	double triangle[][3] = {
		{137.4, 80.9, 0.78},
		{155.2, 92.62, 0.89},
		{149.3, 97.93, 1.35},
		{160.0, 100.25, 9.00},
		{155.6, 68.95, 1.25},
		{149.7, 120.0, 1.75}
	};
	
	int rows = sizeof(triangle)/sizeof(triangle[0]);
	//int cols = sizeof(triangle[0])/sizeof(triangle[0][0]);
	
	int i = 0, j = 0;
	
	double area[rows];
	double largest = 0;
	for(i = 0; i < rows; i++){
		area[i] = find_area(triangle[i]);
		
		printf("Area of triangle %d = %.3lf\n", i+1, area[i]);
		if(largest < area[i]){
			largest = area[i];
			j = i;
		}
	}  
	
	printf("\nLargest area is of %d triangle i.e %.3lf\n",j+1, largest);
	
	return 0;
}
