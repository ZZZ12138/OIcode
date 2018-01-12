#include<iostream>
#include<algorithm>
using namespace std;

struct time{
    int start;
    int end;
    int c_time;
};

time exam[1000000];

bool cmp(time a, time b){
    if(a.end == b.end){
        return a.start < b.start;
    }
    else{
        return a.end < b.end;
    }
}//将结束时间少的排到前面，若一样则排开始时间 

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> exam[i].start;
        cin >> exam[i].end;
        exam[i].c_time = exam[i].end - exam[i].start;
    }
    sort(exam,exam+n,cmp);

    int count = 0;
    int end = 0; 
    for(int i = 0; i < n; i++){
        if(exam[i].start >= end){
            end = exam[i].end;
            count++;
        }
    }
    cout << count;
    return 0; 
    
}
