#include<iostream>
using namespace std;

bool n[100+10][100+10];

int q[100000][2];
int head = 0, tail = 0;

int check(int x, int y);

int main(){
	int n,m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <=m; j++){
			cin >> n[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <=m; j++){
			check(i,j);
		}
	}
	cout << ;
		
	return 0;
}

void push(int x, int y){
	tail++;
	q[tail%999][0] = x;
	q[tail%999][1] = y;
}

void pop(){
	head--;
}

int check(int x, int y){
		if (n[x][y] == 0) return 0;
		if (n[x+1][y] == 1) push(x+1,y);
			
		
}//bug
