#include<iostream>
#include<cstring>
#include<stack>

stack <int>num1;
stack <int>num2;
char n1[1000];
char n2[1000];

int check(int a, int b){
  if(a > b) return a;
  else{
    if(a == b){
      if(n1[0] < n2[0]) cout << "-";
      return a; 
    }
    else{
      cout << "-";
      return b;
    }
  }
}//判断是否为负数并比较a和b的大小

int main(){
  cin >> n1;
  cin >> n2;
  int len1 = strlen(n1);
  int len2 = strlen(n2);
  int max = check(len1, len2);
  
  for(int i = 0; i < len1; i++){
    num1.push(n1[i] - 48);
  }
  for(int i = 0; i < len2; i++){
    num2.push(n2[i] - 48);
  }

  int temp = 0;
  for(int i = 0; i < max; i++){
    
  }


  
  

  return 0;
}
