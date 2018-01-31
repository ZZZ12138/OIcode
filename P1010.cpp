#include<iostream>
#include<stack>
using namespace std;

void fen1(int n);
void fen2(int times);

stack<char> _out;

int main() {
	int n;
	cin >> n; 
	fen1(n);

	char temp;
	if (_out.top() == '+') _out.pop();
	while (!_out.empty()) {
		temp = _out.top();
		_out.pop();
		if (!_out.empty() && temp == '(' && _out.top() == '+') {
			_out.pop();
		}
		cout << temp;

	}
	return 0;
}

void fen1(int n) {
	int count = 0;
	while (n != 0) {
		if (n & 1) {
			if(count > 1) _out.push(')');
			fen2(count);
			if(count > 1) _out.push('(');
			if(count > 1) _out.push('2');
			if (count > 1) _out.push('+');
		}
		n = n >> 1;
		count++;
	}
}

void fen2(int times) {
	if (times == 0) {
		_out.push(')');_out.push('0');_out.push('(');_out.push('2');_out.push('+');
	}
	else {
		if (times == 1) {
			_out.push('2'); _out.push('+');
		}
		else {
			fen1(times);
		}
	}

}