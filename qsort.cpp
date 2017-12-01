#include<iostream>
using namespace std;
int numb[100000+10];

int _in();
void _swap(int &a, int &b);
void qsort(int L, int R);
void _out(int n);
int main(){
	int n = _in();//输入 
	qsort(0,n-1);
	_out(n);
	return 0;
}

int _in(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> numb[i];
	return n;
}//输入 

void _swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}//交换变量 

void qsort(int L, int R){
	 if (L >= R) return;
	 int i = L;
	 int j = R;
	 int temp = numb[(i+j)/2];
	 while (i <= j){
	 	while (temp <= numb[j]) j--;
	 	while (temp >= numb[i]) i++;
	 	if (i <= j){
	 	   _swap(numb[i], numb[j]);	
	 	   i++;
	 	   j--;
	 	}
	 		
	 }
	 qsort(L,j);
	 qsort(i,R);
	 	
}

void _out(int n){
	for (int i = 0; i < n; i++) {
	  	cout << numb[i];
		if(i == n-1) break;
		cout << " ";	
	}
	
}
