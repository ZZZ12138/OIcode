#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int temp;
  cin >> temp;
  cout << temp << "^" << n;
  n--;
  while (n > 0) {
    cin >> temp;
    if (temp == 1) {
      cout << "x^" << n;
      n--;
    }

    if (temp == -1) {
      cout << "-x^" << n;
      n--;
    }
    if (temp == 0) {
      n--;
      continue;
    }
    if (temp > 0) {
      cout << "+" << temp << "x^" << n;
      n--;
    }
    if (temp < 0) {
      cout << temp << "x^" << n;
      n--;
    }
  }
  cin >> temp;
  if (temp > 0)
    cout << "+";
  if (temp == 0)
    return 0;
  cout << temp;
  return 0;
}
