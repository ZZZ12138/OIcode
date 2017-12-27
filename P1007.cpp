#include <iostream>
using namespace std;

int _max(int a, int b){
	if(a >= b) return a;
	else return b;
}
int _min(int a, int b){
	if(a <= b) return a;
	else return b;
}

int main() {
  int L;
  int N;
  cin >> L >> N;
  
  int temp;  
  int min = 0;
  int max = 0;
  for (int i = 1; i <= N; i++) {
  	cin >> temp;
    min = _max(min, _min(temp, L+1-temp));
    max = _max(max, _max(temp,L+1-temp));
  }
  
  cout << min << " " << max;
  return 0;
}
//贪心
