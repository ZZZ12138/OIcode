#include<iostream>
#include<algorithm>
using namespace std;
int numb[5000+10][2];
int out_mark[5000+10];
int out_rand[5000+10]; 
void qsort(int L, int R);
void swap(int &a, int &b);
int main(){
	int m, n;
	cin >> m >> n;
	
	for (int i = 0; i < m; i++){
		cin >> numb[i][0] >> numb[i][1];
	}//1为成绩 
	
	qsort(0,m-1);//将分数和排名同步排序 
	int person_numb = n * 1.5;//人数 
	int mark = numb[m - 1 - person_numb][1];//分数线 
	int count = 0;
	for(int i = m-1; i > 0; i--){//倒着扫排名 
		if (numb[i][1] >= total) {
		   out_mark[count] = numb[i][1];
		   out_rand[count] = numb[i][0];
		   count++;
		}
		else break; 
	}
	
	cout << total << " ";
	cout << count << endl;
	
	for (int i = 0; i < count; i++){
		
	}
		
	
	return 0;
}
void qsort(int L, int R){
	int i = L;
	int j = R;
	if (i >= j) return;
	int temp = numb[(i+j)/2][1];
	while (i <= j){
		while(temp > numb[i][1]) i++;
		while(temp < numb[j][1]) j--;
		if (i <= j) {
			swap(numb[i][1], numb[j][1]);
			swap(numb[i][0], numb[j][0]);
			i++;
			j--;
		}
		
	}
	qsort(L,j);
	qsort(i,R);
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
 	b = temp;
}
