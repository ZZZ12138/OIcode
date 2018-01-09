#include <iostream>
using namespace std;

struct word {
  char a;
  int check;
};
char apl[10] = "yizhong";
int n;
word w[101][101];
int count = 0;
void dfs1(int x, int y);
void dfs2(int x, int y, int dx, int dy, int c);
void input(int x);
void chuli(int x, int y, int dx, int dy);
void print();

int main() {
  cin >> n;
  input(n);
  dfs1(1, 1);
  print();
  return 0;
}

void input(int x) {
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= x; j++) {
      cin >> w[i][j].a;
    }
  }
} //输入方阵

void dfs1(int x, int y) {
  if (x > n || y > n) {
    return;
  } else {
    if (w[x][y].a == apl[0]) {
      dfs2(x, y, -1, -1, 1); //左上
      dfs2(x, y, 0, -1, 1);  //向上
      dfs2(x, y, 1, -1, 1);  //右上
      dfs2(x, y, -1, 0, 1);  //向左
      dfs2(x, y, 1, 0, 1);   //向右
      dfs2(x, y, -1, 1, 1);  //左下
      dfs2(x, y, 0, 1, 1);   //向左
      dfs2(x, y, 1, 1, 1);   //右下
    }
  }
}

void dfs2(int x, int y, int dx, int dy, int c) {
  if (c > 7) {
    chuli(x, y, dx, dy);
    return;
  } //超过7后进行处理并返回
  if (x > n || y > n) {
    return;
  }
  if (w[x + dx][y + dy].a == apl[c]) {
    dfs2(x + dx, y + dy, dx, dy, c + 1);
  } //如果下个字符也相等，继续移动
}

void chuli(int x, int y, int dx, int dy) {
  for (int i = 1; i <= 7; i++) {
    w[x][y].check = 1;
    x -= dx;
    y -= dy;
  }
}

void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (w[i][j].check == 1) {
        cout << w[i][j].a;
      } else {
        cout << "*";
      }
    }
    cout << endl;
  }
}
