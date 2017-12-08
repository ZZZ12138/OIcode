#include<iostream>
using namespace std;
int main(){
	long long n, k;
	cin >> n >> k;
	if (n % 2 == 1) n -= 1;
	cout << n / k;
	return 0;
}
