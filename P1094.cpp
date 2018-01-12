#include<iostream>
#include<algorithm>
using namespace std;

int item[30000+10];

int main(){
	int w;
	int n;
	cin >> w;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> item[i];
	}
	sort(item,item+n);
	int head = 0;
	int end = n - 1;
	int count = 0;
	
	while(head <= end){
		int tot = 0;
		int check = 0;
		if(tot + item[end] <= w && check < 2) {
			tot += item[end];
			end--;
			check++;
		}
		if(tot + item[end] <= w && check < 2){
			tot += item[end];
			end--;
			check++;
		}
		if(tot + item[head] <= w && check < 2){
			tot += item[head];
			head++;
			check++;
		}
		if(tot + item[head] <= w && check < 2){
			tot += item[head];
			head++;
			check++;
		}
		count++;
	}
	cout << count;
	return 0;
}
