#include<iostream>
using namespace std;
int block[30 + 10][30 + 10];

struct point {
	int x;
	int y;
}p;//用来存放扫出来的联通块坐标

void dfs(int x, int y) {
	if (block[x][y] == 1 || block[x][y] == 2) {
		return;
	}
	else {
		block[x][y] = 2;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> block[i][j];
		}
	}

	bool flag = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			if (block[i][j] == 1) {
				if (block[i + 1][j + 1] == 1) continue;
				else {
					p.x = i + 1;
					p.y = j + 1;
					flag = false;
					break;
				}
			}
		}
		if (!flag) break;
	}

	dfs(p.x, p.y);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << block[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
