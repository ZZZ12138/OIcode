#include<iostream>
#include<algorithm>
#include<cmath>
// #define int long long;
using namespace std;

struct person{
  int id;
  int mark;
};

bool cmp(person a, person b){
  if(a.mark == b.mark){
    if(a.id < b.id) return true;
    else return false;
  }
  if(a.mark > b.mark) return true;
  return false;
}

person emmm[5000+10];

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> emmm[i].id >> emmm[i].mark;
  }

  sort(emmm, emmm + n, cmp);
  int temp = 1.5 * m - 1;
  int mark_line = emmm[temp].mark;

  int count = 0;
  for (int i = 0; i < n; i++) {
    if(emmm[i].mark < mark_line) break;
    else count++;
  }
  cout << mark_line << " " << count << endl;
  for (int i = 0; i < count; i++) {
    cout << emmm[i].id << " " << emmm[i].mark;
    if(i != count - 1) cout << endl;
  }

  return 0;
}
