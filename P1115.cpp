#include<iostream>
#include<algorithm>
using namespace std;
int num[200000 + 10];
int main() {
	int n;
	cin >> n;
	long long _max = -10000000;
	for (int i = 1; i <= n; i++){
		cin >> num[i];
		num[i] = max(num[i], num[i] + num[i - 1]);
		if (num[i] > _max) _max = num[i];
	}
	cout << _max;
	return 0;
}