//sort elements in decreasing order

#include <iostream>
#include <cstdlib>

using namespace std;

void quickSort(unsigned A[], int start, int end);
int partition(unsigned A[], int start, int end);
void swap(unsigned *x, unsigned *y);

int main(void){
	
	int testCases = 0;
	cin >> testCases;
	
	while(testCases-- > 0){
		
		int N = 0;
		cin >> N;
		unsigned A[N];
		
		for(int i = 0; i < N; i++){
			
			cin >> A[i];
			
		}
		
		quickSort(A, 0, N-1);
		
		for(int i = 0; i < N; i++){
			
			cout << A[i] << " ";
			
		}
		cout << endl;
		
	}
	
	return 0;
	
}

void quickSort(unsigned A[], int start, int end){
	
	//cout << "inside quickSort\n";
	
	if(start < end){
		
		int pivot = partition(A, start, end);
		
		quickSort(A, start, pivot-1);
		quickSort(A, pivot+1, end);
		
	}
	
}

int partition(unsigned A[], int start, int end){
	//cout << start << " " << end << endl;
	unsigned pivot = A[start];
	int i = start + 1;
	
	for(int j = start+1; j <= end; j++){
		
		if(A[j] > pivot){
			
			swap(&A[j], &A[i]);
			i += 1;
			
		}
		
	}
	
	swap(&A[start], &A[i-1]);
	
	return i-1;
}

void swap(unsigned *x, unsigned *y){
	
	unsigned temp = *x;
	*x = *y;
	*y = temp;
	
}