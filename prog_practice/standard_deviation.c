//WAP to find the standard deviation and mean from given set of sample data
//mean = avg,   std_deviation = under_root((sumation_of(ith_element - mean)square) / number_of_elements)

#include<stdio.h>
#include<math.h>

double find_mean(int a[],int size){
	int i = 0;
	int sum = 0;
	
	for(i = 0; i < size; i++){
		sum += a[i];
	}
	
	return sum/size;
}

double variance(int a[],double mean,int size){
	int i = 0;
	double variance = 0;
	for(i = 0; i < size; i++){
		variance = variance + pow((a[i] - mean), 2);
	}
	variance /= size;
	
	return variance;
}

/*
double sqr_root(double n){
	//Using newton raphson method
	double k = 1.0;
	if((k*k - n) > 0.0000000001 || (n - k*k) > 0.000000001){
		k = (k+ n/k)/2;
	}
	printf("Square root of %.3lf = %.3lf\n",n,k);
	return k;
}
*/
double std_deviation(int a[], int size){
	double mean = find_mean(a, size);
	double varience = variance(a, mean, size);
	return sqrt(varience);
}

//Driver function
int main(void){
	int a[] = {-6, -12, 8, 13, 11, 6, 7, 2, -6, -9, -10, 11, 10, 9, 2};
	int size = sizeof(a)/sizeof(a[0]);
	
	double result = std_deviation(a, size);
	printf("Standard_deviation = %.3lf\n",result);
	
	return 0;
}
