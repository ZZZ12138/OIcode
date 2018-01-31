#include<iostream>
#include<algorithm>
using namespace std;
int a[10];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		a[i] = i + 1;
		cout << "    " << a[i];
	}
	while (next_permutation(a, a + n)) {
		cout << "\n";
		for (int i = 0; i < n; i++) {
			cout << "    " << a[i];
		}
	}
	return 0;
}