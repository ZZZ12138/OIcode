#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

bool check(string &a, string &b) {
	if (a == b) return true;
	if (a.size() > b.size()) return true;
	else {
		if (a.size() == b.size()) {
			if (a[0] > b[0]) return true;//比较首位
			else {
				swap(a, b);
				return false;
			}
		}
		else{
			swap(a, b);
			return false;
		}
	}
}

stack<int> A;
stack<int> B;
stack<int> ANS;


int main() {
	string a;
	string b;
	cin >> a;
	cin >> b;
	string::iterator it_a;
	string::iterator it_b;

	for (it_a = a.begin(); it_a != a.end(); it_a++) {
		if (*it_a - 48 == 0) {
			it_a = a.erase(it_a);
		}
		else {
			break;
		}
	}
	for (it_b = b.begin(); it_b != b.end(); it_b++) {
		if (*it_b - 48 == 0) {
			it_b = b.erase(it_b);
		}
		else {
			break;
		}
	}

	bool flag1 = check(a, b);
	if (!flag1) cout << "-";

	for (it_a = a.begin(); it_a != a.end(); it_a++) {
		A.push(*it_a - 48);
	}
	for (it_b = b.begin(); it_b != b.end(); it_b++) {
		B.push(*it_b - 48);
	}//将数位推入栈中

	while (1) {
		if (A.empty()) break;
		int temp_a = A.top();
		int temp_b = 0;
		if (!B.empty()) {
			temp_b = B.top();
			B.pop();
		}
		A.pop();
		
		int ans = temp_a - temp_b;
		if (ans < 0) {
			ANS.push(10 + ans);
			int temp_j = A.top();
			temp_j--;
			A.pop();
			A.push(temp_j);
		}
		else {
			ANS.push(ans);
		}
	}

	while (ANS.size() != 1 && ANS.top() == 0) {
		ANS.pop();
	}//前导0

	while (!ANS.empty()) {
		cout << ANS.top();
		ANS.pop();
	}
	return 0;
}