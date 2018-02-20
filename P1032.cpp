#include<iostream>
#include<set>
#include<queue>
#include<string>
using namespace std;

string start, end;
int rule_num = 0;
int ans = 0;
struct a_to_b{
	string a, b;
};

struct node{
	string now;
	int step;
};

queue <node>q;
set <string>s;

a_to_b rule[10];

void change(node temp, int rule_place, int str_place){
	int i;
	for(i = 1; i < rule[rule_place].a.size(); i++){
		if(temp.now[str_place+i] != rule[rule_place].a[i]) return;
	}//字符串相等
	
	string str = temp.now.substr(0,str_place);
	str += rule[rule_place].b;
	str += temp.now.substr(i, 99999);
	temp.now = str;
	if(!s.count(temp.now)){
	    temp.step++;
	    q.push(temp);
	    s.insert(temp.now);
	    return;
	}
	else{
	    return;
	}
}


void bfs(){
	node temp;
	temp.now = start;
	temp.step = 0;
	q.push(temp);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp.now == end){
			ans = temp.step;
			return;
		}
		if(s.count(temp.now)) continue;
		if(temp.step > 10) continue;
		
		for(int i = 0; i < rule_num; i++){
			char first = rule[i].a[0];
			for(int j = 0; j < temp.now.size(); j++){
				    cout << temp.now[j];
				if(temp.now[j] == first) {
					change(temp,i,j);
				}
			}
		}
		
		
	}
	
	if(ans > 10 || ans == 0){
		cout << "NO ANSWER";
	}
	else{
		cout << ans;
	}
	
}


int main(){
	cin >> start >> end;
	while(cin >> rule[rule_num].a >> rule[rule_num].b) rule_num++;
	
	bfs();
	return 0;
}
