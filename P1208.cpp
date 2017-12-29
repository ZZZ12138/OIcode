#include<iostream>
#include<algorithm>
using namespace std;

struct milk{
  int milk_price;
  int milk_num;
};

milk m[5000+10];

bool cmp(milk a, milk b){
  if(a.milk_price < b.milk_price) return true;
  else return false;
}


int main(){
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> m[i].milk_price >> m[i].milk_num;
  }
  sort(m,m+M,cmp);

  int tot = 0;
  for(int i = 0; i < M; i++){
    if(m[i].milk_num >= N) {
      tot += m[i].milk_price * N;
      break;
    }
    else{
      N -= m[i].milk_num;
      tot += m[i].milk_price * m[i].milk_num;
    }
  }
  cout << tot;
  return 0;
}
