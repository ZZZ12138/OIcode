#include<iostream>
#include<set>
#include<queue>
using namespace std;

set <int>w;
queue <int>t;
int main() {
	int M, N;//MΪ�ڴ�������NΪ���³���
	cin >> M >> N;
	int p = 0;
	int temp;
	int count = 0;
	for (int i = 0; i < N; i++){
		cin >> temp;
		if (w.count(temp)) {//����ڴ������������
			continue;
		}
		else {
			w.insert(temp);
			t.push(temp);
			p++;
			count++;

			if (p > M) {
				w.erase(t.front());
				t.pop();
				p--;
			}
		}
	}
	cout << count;
	return 0;
}