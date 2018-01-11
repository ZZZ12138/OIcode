#include <algorithm>
#include <iostream>
using namespace std;

int numb[100000 + 10];
int main() {
  int n;
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> numb[i];
  }
  int head = 1;
  int last = n;
  int count = 0;
  while (n > 0) {
    int tot = 0;
    for (int i = last; i >= head; i--) {
      tot += numb[i];
      if (tot <= m) {
        last--;
      } else {
        break;
      }
    }

    for (int i = head; i <= last; i++) {
    }
  }
}
}
