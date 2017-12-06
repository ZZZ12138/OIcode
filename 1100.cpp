#include<iostream>
using namespace std;
int _max(int a, int b);
void emmm();
long long b[100000];

int main(){
	
	int A;
	cin >> A;
	
	for (int i = 0; i < A; i++) {
		cin >> A;
		if (A == 1) cout << "233";
		else cout << "666";
	} //垃圾数组

	int B;
	cin >> B;
	for (int i = 0; i < B; i++){
		cin >> b[i];
	}//输入检查点高度 
	
	int m;
	cin >> m;
	
	int maxn = -1000;
	for (int i = 0; i < B; i++){
		int temp = b[i] - m;
		cout << temp;
		maxn = _max(maxn,temp);
		if(i == B - 1) break;
		cout << " ";
	}
	cout << endl << maxn << endl;
	
	emmm();
	int numb;
	cin >> numb;
	switch(numb){
		case 1 : cout << "bu%Wangchu&Xin!!!";break;
		case 2 : cout << "AlphaGo#Ling$Niu8!";break;
		case 3 : cout << "Shi13Xian11China09Meng";break;
		case 4 : cout << "Diao@yu?DaoWomende";break;
		default : break;
	}
	
	return 0;
}

int _max(int a, int b){
	if(a >= b) return a;
	return b;
}

void emmm(){
	char temp;
	while(1){
		cin >> temp;
		cout << "666" << endl;
		if(temp == 'Y') break;
	}
}
