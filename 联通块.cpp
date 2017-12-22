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
/*
描述:
        一个n * m的方格图，一些格子被涂成了黑色，在方格图中被标为1，白色格子标为0。问有多少个四连通的黑色格子连通块。四连通的黑色格子连通块指的是一片由黑色格子组成的区域，其中的每个黑色格子能通过四连通的走法（上下左右），只走黑色格子，到达该联通块中的其它黑色格子。
输入:
       第一行两个整数n,m(1<=n,m<=100)，表示一个n * m的方格图。
       接下来n行，每行m个整数，分别为0或1，表示这个格子是黑色还是白色。
输出:
        一行一个整数ans，表示图中有ans个黑色格子连通块。
样例输入
3 3
1 1 1
0 1 0
1 0 1
样例输出
3
分
       /*
