#include<iostream>
#include<set>
#include<queue>
#include<string>
using namespace std;

string _start, _end;
int rule_num = 0;
int ans = 0;
struct a_to_b {
	string a, b;
};

struct node {
	string now;
	int step;
};

queue <node>q;
set <string>s;
a_to_b rule[10];

void change(node temp, int rule_place, int str_place) {
	int i;
	for (i = 1; i < rule[rule_place].a.size(); i++) if (temp.now[str_place + i] != rule[rule_place].a[i]) return;//字符串相等
	int last_len = temp.now.size() - str_place - rule[rule_place].a.size();

	string str = temp.now.substr(0, str_place);//复制被替换的字符串前的内容
	str += rule[rule_place].b;//复制替换后的字符串
	str += temp.now.substr(str_place + i, last_len);//复制被替换的字符串后的内容，这里有个坑
	temp.now = str;
	if (!s.count(temp.now)) {
		s.insert(temp.now);
		temp.step++;
		q.push(temp);
		return;
	}
	else return;
}

void bfs() {
	node temp;
	temp.now = _start;
	temp.step = 0;
	q.push(temp);
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp.now == _end) {
			ans = temp.step;
			return;
		}

		if (temp.step > 10) continue;

		for (int i = 0; i < rule_num; i++) {
			char first = rule[i].a[0];
			for (int j = 0; j < temp.now.size(); j++) {
				if (temp.now[j] == first) {
					change(temp, i, j);
				}
			}
		}
	}
}


int main() {
	cin >> _start >> _end;
	while (cin >> rule[rule_num].a >> rule[rule_num].b) rule_num++;
	bfs();
	if (ans == 0) cout << "NO ANSWER!";
	else cout << ans;
	return 0;
}
