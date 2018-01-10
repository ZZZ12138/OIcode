#include <algorithm>
#include <iostream>
using namespace std;

struct student {
  int chinese_mark;
  int math_mark;
  int english_mark;
  int id;
  int tot_mark;
};

student emmm[300 + 10];

bool cmp(student a, student b) {
  if (a.tot_mark == b.tot_mark) {
    if (a.chinese_mark == b.chinese_mark) {
      return a.id < b.id;
    } else {
      return a.chinese_mark > b.chinese_mark;
    }
  } else {
    return a.tot_mark > b.tot_mark;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> emmm[i].chinese_mark;
    cin >> emmm[i].math_mark;
    cin >> emmm[i].english_mark;
    emmm[i].id = i + 1;

    emmm[i].tot_mark =
        emmm[i].chinese_mark + emmm[i].math_mark + emmm[i].english_mark;
  }
  sort(emmm, emmm + n, cmp);
  for (int i = 0; i < 5; i++) {
    cout << emmm[i].id << " " << emmm[i].tot_mark << endl;
  }
  return 0;
}
