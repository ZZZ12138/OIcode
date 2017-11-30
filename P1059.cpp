#include<iostream>
#include<algorithm>
using namespace std;
int numb[100+10];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> numb[i];
	
	sort(numb,numb+n);
	
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (numb[i] == numb[j]){
			   numb[j] = 0;
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i < n; i++){
		if (numb[i] != 0) count++;
	}
	
	cout << count << endl;
	for (int i = 0; i < n; i++){
		if(numb[i] == 0) continue;
		cout << numb[i];
		if (i == n-1) break;
		cout << " ";
	}
	return 0;
}
