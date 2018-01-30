#include<iostream>
#include<queue>
using namespace std;

int num[100 + 10];
queue<int> temp;

void mergesort(int first, int last);
void merge_addup(int first, int mid, int last);

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	mergesort(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << num[i] << " ";
	}
	return 0;
}

void mergesort(int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		mergesort(first, mid);
		mergesort(mid + 1, last);
		merge_addup(first, mid, last);
	}
}

void merge_addup(int first, int mid, int last) {
	int p1 = first;
	int p2 = mid + 1;

	while (p1 <= mid && p2 <= last) {
		if (num[p1] <= num[p2]) {
			temp.push(num[p1++]);
		}
		else {
			temp.push(num[p2++]);
		}
	}
	while (p1 <= mid) {
		temp.push(num[p1++]);
	}
	while (p2 <= last) {
		temp.push(num[p2++]);
	}

	while (!temp.empty() && first <= last) {
		num[first++] = temp.front();
		temp.pop();
	}
}
