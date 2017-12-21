#include <iostream>
using namespace std;

struct list {
  int data;
  int next;
}; //生成节点

list round[101];

void round_complete(int n) {
  for (int i = 1; i <= n; i++) {
    round[i].data = i;

    if (i == n) {
      round[i].next = 1;
      break;
    } else {
      round[i].next = i + 1;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  round_complete(n);

  int p = round[n].data;
  while (n > 0) {
    if (n == 1) {
      cout << round[p].data;
      break;
    }

    for (int i = 1; i < m; i++) {
      p = round[round[p].next].data;
    } //拿到出圈人的编号
    cout << round[p].next << " ";
    round[p].next = round[round[p].next].next;
    n--;
  }

  return 0;
}
