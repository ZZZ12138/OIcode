#include<iostream>
#include<string>
using namespace std;

int main() {
	string temp;
	cin >> temp;
	string::iterator it;//����������
	for (it = temp.begin(); it != temp.end(); it++) {
		cout << *it;
		//�ǵü�"*"
	}//����temp
	return 0;
}//iterator_demo