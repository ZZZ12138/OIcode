#include<iostream>
using namespace std;
int max_yueshu(long long a, long long b);
void _swap(long long &a, long long & b);
int main(){
	cout << max_yueshu(100,20);
	return 0;
}

int max_yueshu(long long a, long long b){
	if (a < b) _swap(a,b);//a>b
	if (a % b == 0) return b;
	
	long long c = a % b;
	max_yueshu(b,c);
}

void _swap(long long &a, long long &b){
	long temp = b;
	b = a;
	a = temp;	 
}
