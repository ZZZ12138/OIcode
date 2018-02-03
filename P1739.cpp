#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<int> emmm;

int main() {
	string temp;
	cin >> temp;
	string::iterator it;
	for (it = temp.begin(); it != temp.end(); it++) {
		if (*it == '(') {
		    emmm.push(1);
		    continue;
		}
		if (*it == ')') {
		    if(!emmm.empty()){
		        emmm.pop();
		    }
		    else{
		        emmm.push(1);
		        break;
		    }
		}
	}
	if (emmm.empty()) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}