#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char numb[20][110];
int check_numb[2][25];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> numb[i];
	}
	
	int maxn = -10; 
	for (int i = 1; i <= n; i++){
		check_numb[1][i] = check_numb[0][i] = strlen(numb[i]);//字符串长度  
	}
	sort(check_numb[1],check_numb[1]+n);//排序check_numb[1]emmm 
	
	
	
	if (check_numb[1][n] > check_numb[1][n-1]){
		for (int i = 1; i <= n; i++){
			if (check_numb[0][i] == check_numb[1][n]){
				cout << i << " ";
				cout << numb[i];
			} 
		} //找出check_numb[0]中对应的数 
		
		return 0;
	}//如果n为最大位数，直接输出
	 
	else{
		int count = 0;
		int max_len = check_numb[1][n];
		for (int i = n; i > 0; i++){
			if(max_len == check_numb[1][i]) count++;//栈溢出 
		}//找出最大的相同的几个数 
		
		
	}
	
	
	
	
	return 0;
}
