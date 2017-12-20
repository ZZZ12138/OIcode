#include <iostream>
using namespace std;
template <typename T> 
T _max(T a, T b) { return a > b ? a : b; }
int main() {
  char a, b;//T为char（传入的类型）
  cin >> a >> b;
  cout << _max(a, b) << endl;
  return 0;
}
//demo_template
