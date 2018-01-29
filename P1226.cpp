#include<iostream>
using namespace std;
long long fast(long long base, long long n, long long c) {
	if (n == 0) {
		return 1;
	}
	else {
		long long  k = fast(base, n >> 1, c);
		if (n % 2 == 0) {
			return k * k % c;
		}
		else {
			return k * k * base % c;
		}
	}
}

int main() {
	long long b, p, k;
	cin >> b >> p >> k;
	cout << b << "^" << p << " mod " << k << "=" << fast(b, p, k);
	return 0;
}
