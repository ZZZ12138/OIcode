#include<iostream>
using namespace std;
void qsort(int left, int right);
void swap(int &a,int &b);
int numb[100000+10];

int main(){
  int count;
  cin >> count;
  for (int i = 0; i < count; i++) {
    cin >> numb[i];
  }

  qsort(0,count-1);

  cout << numb[0];
  for (int i = 1; i < count; i++) {
    cout << " " << numb[i];
  }
  return 0;
}


void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}//交换变量


void qsort(int left, int right){
  int i = left;
  int j = right;
  int temp = numb[left];

  if (left > right) return;
  while (i != j) {
    while (temp <= numb[j] && i < j) j--;
    while (temp >= numb[i] && i < j) i++;

    if (i < j) swap(numb[i],numb[j]);
  }
  
  numb[left] = numb[i];
  numb[i] = temp;
  qsort(left,i-1);
  qsort(i+1,right);
}
