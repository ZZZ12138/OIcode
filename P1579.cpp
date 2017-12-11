#include<iostream>
#include<algorithm> 
using namespace std;
int _count = 0;
int numb[10];
bool primer[20000+10];
void check_primer(int n);
void check(int n);

int main(){
	check_primer();
	int n;
	cin >> n;
	check(n);
	return 0;
}

void check_primer(int n){
	for (int i = 1; i <= n; i++) primer[i] = 1;
	primer[1] = 0;//1不是质数 
	for(int i = 2; i <= n ; i++){
		for (int j = 2; j <= 10000; j++){
			int m = i * j;
			if(m > 20000) break;
			else primer[m] = 0;
		}
		
	}
}//先扫一遍质数 

void _out(int a, int b, int c){
	/*cout  << "raw:" << a <<" "<< b <<" "<< c << endl;*/
	int temp = numb[0];
	numb[0] = a;
	numb[1] = b;
	numb[2] = c;
	sort(numb,numb+3);
	
	if (_count == 1) cout << endl;//第二组换行 	 
	cout << numb[0] << " " << numb[1] << " " << numb[2];
	_count++;
}//bug 

void check(int n){
	 for (int i = 2; i < 20000; i++){
		if(primer[i] == 0) continue;
		for (int j = 2; j < 20000; j++){	
			if(primer[j] == 0) continue;	
			for (int m = 2; m < 20000; m++){		
				if(primer[m] == 0) continue;			
				else{
					if ((i+j+m) == n) _out(i,j,m);
					if (_count == 2) return;//达到两组后退出 
				}
			}
		}
	} 
}
