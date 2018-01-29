#include<iostream>
using namespace std;
long long fast(long long base, long long n) {
	if (n == 0) {
		return 1;//分到尽头
	}
	else {
		long long  k = fast(base, n / 2);//持续分成两份
		if (n % 2 == 0) {
			return k * k;
		}
		else {
			return k * k * base;//如果n是奇数则需再乘以一个base
		}
	}
}


int main() {
	long long base, power_times;
	cin >> base >> power_times;
	cout << fast(base, power_times);
	return 0;
}
