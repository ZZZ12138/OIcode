#include<iostream>
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
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> exam.start;
        cin >> exam.end;
        c_time = exam.end - exam.start;
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
    
}
