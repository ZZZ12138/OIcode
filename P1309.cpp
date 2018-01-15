#include<iostream>
using namespace std;

struct person{
    int id;
    int power;
    int mark;
};

person player[200000+10];

bool cmp1(person a, person b){
    if(a.mark == b.mark) return a.id < b.id;
    else return a.mark > b.mark;
}

int main(){
    int n;
    int r;
    int q;
    cin >> n >> r >> q;
    for(int i = 1; i <= 2*n; i++){
        player[i].id = i;
        cin >> player[i].mark;
    }
    for(int i = 1; i <= 2*n; i++){
        cin >> player[i].power;
    }
    sort(player+1,player+1+2*n,cmp1);[p;/'']
    for(int i = 1; i <= 2*n; i += 2){

    }


}
