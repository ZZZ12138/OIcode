#include<iostream>
#include<algorithm> 
using namespace std;
int person[2][5000+10];
int sort_mark[5000+10];
int out_person[2][5000+10];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> person[0][i] >> person[1][i];
		sort_mark[i] = person[1][i];
	}//输入选手数据并复制到另一数组排序 
	
	sort(sort_mark,sort_mark+n);
	
	int pre = m * 1.5;
	int min_mark;
	int count_person = 0;
	int count_person_continue = 0;
	
	
	for (int i = n - 1; i >= n - pre; i--){
		if(sort_mark[i] == sort_mark[i-1]) {
			count_person_continue++;
			continue;//遇到同分数的找最后一个 
		}
		for (int j = 0; j < n; j++){
			if(person[1][j] == sort_mark[i]) {
				out_person[0][count_person] = person[0][j];
				out_person[1][count_person] = person[1][j];
				min_mark = out_person[1][count_person];
				count_person++;
			}
		}
	}//排序后找出与之前对应的选手
	
	
/*	for (int i = n-1; i >= n-pre; i--){
		if(sort_mark[i] == sort_mark[i-1]) continue;//遇到同分数的找最后一个 
		int count_the_same_mark = 0;
			for (int j = 0; i < n; j++){
				if(person[1][j] == sort_mark[i]) {
					out_person[0][count_person] = person[0][j];
					out_person[1][count_person] = person[1][j];
					min_mark = out_person[1][count_person];
					count_person++;
					count_the_same_mark++;
			}
		}
		 
	}*/
	
	
	cout << "end" << endl;
	
	cout << min_mark << " " << count_person_continue + count_person << endl;
	for(int i = 0; i < count_person_continue + count_person; i++){
		cout << out_person[0][i] << " " << out_person[1][i];
		if (i == count_person - 1) break; 
		cout << endl;
	}//输出 
	
	return 0;
	
}
