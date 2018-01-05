#include<iostream>
#include<algorithm>
using namespace std;

struct num{
	string mark;
	int id;
};

num N[20+1];

bool cmp(num a, num b){
	int a_len = a.mark.length();
	int b_len = b.mark.length();
	if (a_len > b_len){
		return true;
	}
	else{
		if(a_len == b_len){
			if(a.mark > b.mark) return true;
			else return false;
		}
		else {
			return false;
		}
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		N[i].id = i + 1;
		cin >> N[i].mark;
	}
	
	sort(N, N+n, cmp);
	cout << N[0].id << endl << N[0].mark;
	return 0;
}

//一定要分类讨论.....
