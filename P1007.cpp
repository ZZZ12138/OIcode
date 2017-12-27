#include <iostream>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
} //交换变量

int main() {
  int L;
  int N;
  cin >> L >> N;

  int temp1;
  int temp2;
  cin >> temp2;
  for (int i = 0; i < N; i++) {
    cin >> temp1;
    swap(temp1, temp2);
  }
}
//Not complete and lots of bugs
