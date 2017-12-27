#include <iostream>
using namespace std;
int p[100 + 10];
int main() {
  int n;
  cin >> n;
  int tot = 0;

  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    tot += p[i];
  }
  tot /= n;
  for (int i = 1; i <= n; i++) {
    p[i] -= tot;
  }

  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i] != 0) {
      p[i + 1] += p[i];
      count++;
    }
  }
  cout << count;
  return 0;
}
