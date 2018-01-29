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
			block[i][j] = temp1[j - 1] - 48;//第一个为x，第二个为y
		}
	}
}

int tot;

void dfs(int x, int y) {
	if (x > n || x < 1 || y > n || y < 1) return;
	if (temp[x][y] > 0) return;
	else {
		temp[x][y] = 1;//打上标记
		tot++;//当前联通块+1
		if (block[x + 1][y] != block[x][y]) dfs(x + 1, y);
		if (block[x - 1][y] != block[x][y]) dfs(x - 1, y);
		if (block[x][y + 1] != block[x][y]) dfs(x, y + 1);
		if (block[x][y - 1] != block[x][y]) dfs(x, y - 1);
	}

}

void push_ans(int x, int y) {
	if (x > n || x < 1 || y > n || y < 1) return;
	if (ans[x][y] > 0) return;
	else {
		ans[x][y] = tot;
		if (block[x + 1][y] != block[x][y]) push_ans(x + 1, y);
		if (block[x - 1][y] != block[x][y]) push_ans(x - 1, y);
		if (block[x][y + 1] != block[x][y]) push_ans(x, y + 1);
		if (block[x][y - 1] != block[x][y]) push_ans(x, y - 1);
	}
}

int main() {
	in();
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (temp[x][y] != 0) {
			cout << ans[x][y] << endl;
		}
		else {
			tot = 0;
			dfs(x, y);
			push_ans(x, y);
			cout << ans[x][y] << endl;
		}
	}
	return 0;
}
