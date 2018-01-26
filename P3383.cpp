#include <cmath>
#include <iostream>
using namespace std;

bool prime[10000000 + 10];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 2; i <= sqrt(N); i++) {
    for (int j = 1; i * j <= N; j++) {
      prime[i * j] = 1;
    }
  }

  prime[2] = 0;
  prime[3] = 0;
  int temp;
  for (int i = 1; i <= M; i++) {
    cin >> temp;
    if (prime[temp] == 1)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
