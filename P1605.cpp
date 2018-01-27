#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int road[10][10];
int temp[10][10]; 
int COUNT = 0;
int sx, sy;
int fx, fy;

void dfs(int dx, int dy){
  if(dx == fx && dy == fy){
    COUNT++; 
    return;
  }//遇到终点返回并加一
  if(temp[dx][dy] == 1){
    return;
  }//遇到路障返回
  
  else{
      temp[dx][dy] = 1;
      
      if(temp[dx-1][dy] == 0 && road[dx-1][dy] == 0) {
        dfs(dx-1,dy);
		temp[dx-1][dy] = 0;	
	  }
      if(temp[dx+1][dy] == 0 && road[dx+1][dy] == 0) {
        dfs(dx+1,dy);
		temp[dx+1][dy] = 0;	
	  }
      if(temp[dx][dy-1] == 0 && road[dx][dy-1] == 0) {
        dfs(dx,dy-1);
		temp[dx][dy-1] = 0;	
	  }
      if(temp[dx][dy+1] == 0 && road[dx][dy+1] == 0) {
        dfs(dx,dy+1);
		temp[dx][dy+1] = 0;	
	  }
  }

}

int main(){
  int N, M;//N为横行，M为纵列
  int T;
  cin >> N >> M >> T;

  cin >> sx >> sy;
  cin >> fx >> fy;
  for (int i = 0; i < T; i++) {
    int dx;
    int dy;
    cin >> dx >> dy;
    road[dx][dy] = 1;
  }

  for (int i = 0; (i <= N+1 || i <= M+1); i++) {
    road[0][i] = 1;
    road[N+1][i] = 1;
    road[i][0] = 1;
    road[i][M+1] = 1;
  }//设定边界

  dfs(sx, sy);
  cout << COUNT;
  return 0;
}

