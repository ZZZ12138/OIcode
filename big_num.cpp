#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

stack<char> num1;
stack<char> num2;

stack<int> out_num;

char n1[10000];
char n2[10000];


int max_len(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int main() {
	cin >> n1;
	cin >> n2;
	int len1 = strlen(n1);
	int len2 = strlen(n2);

	int max = max_len(len1, len2);

	for (int i = 0; i < len1; i++) {
		num1.push(n1[i]);
	}
	for (int i = 0; i < len2; i++) {
		num2.push(n2[i]);
	}

	int temp = 0;
	int total;
	for (int i = 0; i <= max; i++) {
		int temp1 = 0;
		int temp2 = 0;
		if (!num1.empty()) {
			temp1 = num1.top() - 48;
			num1.pop();
		}
		if (!num2.empty()) {
			temp2 = num2.top() - 48;
			num2.pop();
		}
		total = temp + temp1 + temp2;
		out_num.push(total % 10);
		temp = total / 10;
	}

	while (!out_num.empty()) {
		cout << out_num.top();
		out_num.pop();
	}

	return 0;
}
