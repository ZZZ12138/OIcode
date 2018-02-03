#include<iostream>
#include<algorithm>
using namespace std;

struct point {
    int x;
    int y;
}p;
int N;
int K = 1;
int num[40 + 10][40 + 10];


void complete() {
    if (p.x == 1 && p.y != N) {
        num[N][++p.y] = K;
        K++;
        p.x = N;
        return;
    }//1

    if (p.y == N && p.x != 1) {
        num[--p.x][1] = K;
        K++;
        p.y = 1;
        return;
    }//2

    if (p.x == 1 && p.y == N) {
        num[++p.x][p.y] = K;
        K++;
        return;
    }//3

    if (p.x != 1 && p.y != N) {
        if (num[p.x - 1][p.y + 1] == 0) {
            num[--p.x][++p.y] = K;
            K++;
            return;
        }
        else{
            num[++p.x][p.y] = K;
            K++;
            return;
        }
    }//4
}

int main() {
    cin >> N;
    p.x = 1;
    p.y = N / 2 + 1;
    num[p.x][p.y] = K;
    K++;
    for (int i = 1; i < N * N; i++){
        complete();
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++){
            cout << num[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}