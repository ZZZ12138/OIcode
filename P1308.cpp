#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  string temp;
  string word;
  cin >> word;
  transform(word.begin(), word.end(), word.begin(),::tolower);

  int count = 0;
  int place = 0;
  int min_place = -1;
  while(getline(cin,temp)){
  	transform(temp.begin(), temp.end(), temp.begin(),::tolower);
  	if(word == temp) {
  		count++;
  		if(min_place == -1) min_place = place;
  	}
  	place++;
  }
  cout << count << " " << min_place;
  return 0;
}
