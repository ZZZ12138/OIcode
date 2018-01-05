#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

struct person{
	int W;
	int D;
	int id;
};

person N[20000+10];

int E[11];

bool cmp(person a, person b){
	if(a.W == b.W){
		if(a.id < b.id) return true;
		else return false;
	}
	if(a.W > b.W) return true;
	else return false;
}


int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 10; i++){
		cin >> E[i];
	}//E的权值
	
	for (int i = 0; i < n; i++){
		cin >> N[i].W;
		N[i].id = i+1;
	} //初始的权值W
	
	sort(N, N+n, cmp);

	for (int i = 0; i < n; i++){
		N[i].D = i + 1;//序号 
		N[i].W += E[(N[i].D - 1) % 10+1];
	}//加序号 
 
	 
	sort(N, N+n,cmp);
		
	cout << N[0].id;
	for (int i = 1; i < k; i++){
		cout << " " << N[i].id;
	}
	
	return 0;
}

//一定要看题emmm
