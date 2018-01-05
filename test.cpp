#include <iostream>
using namespace std;

int numb[10][10];
int N;
int max_tot = 0;

int max(int a, int b) {
  if (a >= b)
    return a;
  else
    return b;
}

void dfs(int x, int y, int tot) {
  tot += numb[x][y];
  if (x >= N || y >= N) {
    max_tot = max(max_tot, tot);
    return;
  } else {
    dfs(x + 1, y, tot);
    dfs(x + 1, y + 1, tot);
    return;
  }
}

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++) {
      cin >> numb[i][j];
    }
  dfs(1, 1, 0);
  cout << max_tot;
  return 0;
}
