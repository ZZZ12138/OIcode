#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

char num1[2000 + 10];
char num2[2000 + 10];
int ans[4000 + 10];
int main() {
	cin >> num1;
	cin >> num2;
	int len1 = strlen(num1);
	int len2 = strlen(num2);


	for (int i = 0; i < len2; i++) {
		for (int j = 0; j < len1; j++) {
			int temp = (num1[len1 - j - 1] - 48) * (num2[len2 - i - 1] - 48);
			ans[i + j] += temp % 10;
			ans[i + j + 1] += temp / 10;

			if (ans[i + j] >= 10) {
				ans[i + j + 1] += ans[i + j] / 10;
				ans[i + j] = ans[i + j] % 10;
				cout << "1";
			}
		}
	}
	for (int i = 0; i <= 4; i++) {
		cout << ans[i];
	}
	return 0;
}
