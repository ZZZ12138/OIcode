#include<iostream>
#include<set>
#include<queue>
using namespace std;

set <int>w;
queue <int>t;
int main() {
	int M, N;//M为内存容量，N为文章长度
	cin >> M >> N;
	int p = 0;
	int temp;
	int count = 0;
	for (int i = 0; i < N; i++){
		cin >> temp;
		if (w.count(temp)) {//如果内存中有这个单词
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