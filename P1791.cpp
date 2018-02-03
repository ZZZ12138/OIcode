#include<iostream>
#include<algorithm>
using namespace std;

struct line_single {
	int start;
	int end;
	int len;
};

line_single line[10000 + 10];

bool cmp(line_single a, line_single b) {
	return a.end < b.end;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> line[i].start >> line[i].end;
		if (line[i].start > line[i].end) {
			swap(line[i].start, line[i].end);
		}
		line[i].len = line[i].end - line[i].start;
	}

	sort(line, line + n, cmp);
	int del = 0;
	int tail = -2000;
	for (int i = 0; i < n; i++){
		if (line[i].start < tail) {
			del++;
			continue;
		}
		else {
			tail = line[i].end;
		}
	}
	cout << n - del;
	return 0;
}