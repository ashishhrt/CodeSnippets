//Calculate 7n/8 withouth using division or multiplication function
#include<iostream>
#include<string>

using namespace std;
using std::string;

int addZero(int copy_n){
	 //cout << "inside addZero copy_n = " << copy_n << endl;
	 int copy_n_copy = copy_n;
          for(int i = 1; i < 10; i++){
          	 copy_n += copy_n_copy;
			//cout << copy_n << endl;
          }
	return copy_n;
}

int find(int copy_n){
	const int divisor = 8;
	const int mul = 7;
	int integer = 0;
	int decimal = 0;
	int copy_n_copy;
	string str;
	float result;

	while(copy_n >= divisor){
		copy_n -= divisor;
		integer += 1;
	}
	if(copy_n == 0){
		int copy_int = integer;
		for(int i = 0; i < mul - 1; i++)
			integer += copy_int;
		return integer;
	}
	
	else{
		
		while(to_string(decimal).length() < 3){
			copy_n_copy = addZero(copy_n);
			//cout << copy_n_copy << endl;
			while(copy_n_copy >= divisor){
				copy_n_copy -= divisor;
				decimal += 1;
			}
			decimal = addZero(decimal);
			copy_n = copy_n_copy;
			if(copy_n_copy == 0)
				break;
		}
		str = to_string(integer) + "." + to_string(decimal);
		result = stof(str);
		//cout << result << endl;
		float result_copy = result;
		//cout << result_copy << endl;
		for(int i = 0; i < mul - 1; i++){
			result += result_copy;
		}

		int final_result = static_cast<int>(result);

		return final_result + 1;
	}
}

int main(void){
	int n;
	
	cout << "Enter an integer\t";
	cin >> n;
	
	int result = find(n);
	cout << "celling function = " << result << endl;
	
	return 0;
}
