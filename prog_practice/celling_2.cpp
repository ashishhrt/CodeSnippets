//Calculate celling of (7n)/8
//Logic 1. calculate floor of n/8 by using bitwise right shift operator i.e n >> 3   2. subtract floor of n/8 by n, this will give the celling of (7n)/8

#include<iostream>

using namespace std;

int seventimesofnbyeight(int n){
	return (n - ( n >> 3));                             //here second brackets are important because '-' has higher priority than '>>' operator
}

//driver function
int main(void){
	int n;
	cout << "Enter a number \t";
	cin >> n;
	cout << "Answer = " << seventimesofnbyeight(n) << endl;
	return 0;
}
 
