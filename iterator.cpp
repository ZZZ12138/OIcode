#include<iostream>
#include<string>
using namespace std;

int main() {
	string temp;
	cin >> temp;
	string::iterator it;//迭代器创建
	for (it = temp.begin(); it != temp.end(); it++) {
		cout << *it;
		//记得加"*"
	}//遍历temp
	return 0;
}//iterator_demo