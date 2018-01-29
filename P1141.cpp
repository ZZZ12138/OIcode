#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int temp[1000 + 10][1000 + 10];
int block[1000 + 10][1000 + 10];
int ans[1000 + 10][1000 + 10];

struct point {
	int x;
	int y;
};


int n, m;

void in() {
	cin >> n >> m;
	string temp1;
	for (int i = 1; i <= n; i++) {
		cin >> temp1;
		for (int j = 1; j <= n; j++)
		{
			block[i][j] = temp1[j - 1] - 48;
		}
	}
}

int tot;

void dfs(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > n) {
		return;//超出边界
	}
	if (temp[x][y] != 0) {
		return;//被搜索过
	}

	tot++;
	temp[x][y] = 1;
	int temp1 = block[x][y];
	if (block[x - 1][y] != temp1) {
		dfs(x - 1, y);
	}
	if (block[x + 1][y] != temp1) {
		dfs(x + 1, y);
	}
	if (block[x][y - 1] != temp1) {
		dfs(x, y - 1);
	}
	if (block[x][y + 1] != temp1) {
		dfs(x, y + 1);
	}
	ans[x][y] = tot;
}

int main() {
	in();
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (ans[x][y] != 0) {
			cout << ans[x][y] << endl;
		}
		else {
			tot = 0;
			dfs(x, y);
			cout << ans[x][y] << endl;
		}
	}
	return 0;
}
