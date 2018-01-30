#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

struct person {
	int id;
	int mark;
	int power;
};

person player[200000 + 10];
queue<person> winner;
queue<person> loser;
queue<person> tot;

bool cmp(person a, person b) {
	if (a.mark == b.mark) return a.id < b.id;
	else return a.mark > b.mark;
}

void mergesort() {
	while (!winner.empty() && !loser.empty()) {
		int w_mark = winner.front().mark;
		int l_mark = loser.front().mark;
		if (w_mark > l_mark) {
			tot.push(winner.front());
			winner.pop();
		}//分数较大者直接入tot
		else {
			if (w_mark == l_mark) {
				int w_id = winner.front().id;
				int l_id = loser.front().id;
				if (w_id < l_id) {
					tot.push(winner.front());
					winner.pop();
				}
				else {
					tot.push(loser.front());
					loser.pop();
				}//id较小者入tot
			}
			else {
				tot.push(loser.front());
				loser.pop();
			}
		}
	}

	while (!winner.empty()) {
		tot.push(winner.front());
		winner.pop();
	}
	while (!loser.empty()) {
		tot.push(loser.front());
		loser.pop();
	}//用tot储存新的排名
	return;
}

int main() {
	int N, R, Q;
	cin >> N >> R >> Q;
	N *= 2;
	for (int i = 1; i <= N; i++){
		player[i].id = i;
		cin >> player[i].mark;
	}
	for (int i = 1; i <= N; i++){
		cin >> player[i].power;
	}
	sort(player + 1, player + N + 1, cmp);//比赛前排序

	for (int i = 1; i <= N; i++) {
		tot.push(player[i]);
	}

	for (int i = 0; i < R; i++){
		for (int j = 1; j <= N; j += 2) {
			person a = tot.front();
			tot.pop();
			person b = tot.front();
			tot.pop();
			if (a.power > b.power) {
				a.mark++;
				winner.push(a);
				loser.push(b);
			}
			else {
				b.mark++;
				winner.push(b);
				loser.push(a);
			}//赢的人入队winner，输的人入队loser
		}
		mergesort();
	}

	for (int i = 1; i < Q; i++) {
		tot.pop();
	}

	cout << tot.front().id;
	return 0;
}
