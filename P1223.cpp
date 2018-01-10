#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

struct nn {
  int id;
  int t;
  int tot;
};

struct nn n[1000000];

bool cmp(nn a, nn b) {
  if (a.t == b.t) {
    return a.id < b.id;
  } else {
    return a.t < b.t;
  }
}

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    n[i].id = i;
    cin >> n[i].t;
  }
  sort(n + 1, n + N + 1, cmp);
  long long total = 0;
  for (int i = 1; i <= N; i++) {
    cout << n[i].id << " ";
    if (i == 1) {
      n[i].tot = 0;
    } else {
      n[i].tot = n[i - 1].t + n[i - 1].tot;
      total += n[i].tot;
    }
  }
  cout << endl << fixed << setprecision(2) << (double)total / N;
  return 0;
}
