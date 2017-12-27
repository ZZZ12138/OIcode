#include<iostream>
#include<algorithm>
using namespace std;

int fruit[10000+10];

void _swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		cin >> fruit[i];		
	}
	sort(fruit, fruit+n+1);
	
	
	int tot = 0;
	for (int i = 2; i <= n; i++){
		fruit[i] = fruit[i] + fruit[i-1];
		tot += fruit[i]; 
//		cout << fruit[i] << endl;
		int m = i;
		while(fruit[m+1] < fruit[m] || m < n){
			_swap(fruit[m+1], fruit[m]);
			m++;
		}//用冒泡排序将新的果子堆扔到合适的位置（冒泡排序的思想） 
		
	}
	cout << tot;
	return 0;
}
