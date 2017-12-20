#include<iostream>
using namespace std;

struct list{
	int data;
	int next;
	
};

list round[101];

void round_complete(int n){
	for(int i = 1; i <= n; i++){
		round[i].data = i;
		
		if (i == n) {
			round[i].next = 1;
			break;
		}
		else{
			round[i].next = i+1;	
		}
		
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	round_complete(n);
	while(n){
		int p, q;
		for(int i = 1; i <= m; i++){
			p = round[p].next;
			q = 
		}//拿到出圈人的编号
		
		
		
	}
		
	
	
	return 0;
}
