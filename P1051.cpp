#include <algorithm>
#include <iostream>
using namespace std;

struct Student {
  char Name[100];
  int pj_mark;
  int bj_mark;
  char ismonitor;
  char iswest;
  int paper;
  int tot;
  int num;
};

Student S[100 + 10];

bool cmp(Student a, Student b) {
  if (a.tot == b.tot) {
    if (a.num < b.num)
      return true;
    else
      return false;
  }
  if (a.tot > b.tot)
    return true;
  else
    return false;
}

int main() {
  int n;
  cin >> n;
  int tot_tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> S[i].Name;
    cin >> S[i].pj_mark;
    cin >> S[i].bj_mark;
    cin >> S[i].ismonitor;
    cin >> S[i].iswest;
    cin >> S[i].paper;
    S[i].num = i;

    if (S[i].pj_mark > 80 && S[i].paper > 0) {
      S[i].tot += 8000; // 1
    }

    if (S[i].pj_mark > 85 && S[i].bj_mark > 80) {
      S[i].tot += 4000; // 2
    }

    if (S[i].pj_mark > 90) {
      S[i].tot += 2000; // 3
    }

    if (S[i].pj_mark > 85 && S[i].iswest == 'Y') {
      S[i].tot += 1000; // 4
    }

    if (S[i].bj_mark > 80 && S[i].ismonitor == 'Y') {
      S[i].tot += 850; // 5
    }

    tot_tot += S[i].tot;
  }

  sort(S, S + n, cmp);
  cout << S[0].Name << endl << S[0].tot << endl << tot_tot;
  return 0;
}
