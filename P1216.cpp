#include<iostream>
#include<algorithm>
using namespace std;
int _num[1000+10][1000+10];
int _maxsum(int num){
	for(int i = num - 1; i > 0; i--){
		for(int j = 1; j <= i; j++){
			_num[i][j] = max(_num[i+1][j], _num[i+1][j+1]) + _num[i][j];
		}
	}	
	return _num[1][1];
}
int main(){
	int _line_num;
	cin >> _line_num;
	for(int i = 1; i <= _line_num; i++){
		for(int j = 1; j <= i; j++){
			cin >> _num[i][j];
		}
	}
	cout << _maxsum(_line_num);
	return 0;
}
