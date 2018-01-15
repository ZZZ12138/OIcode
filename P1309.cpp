#include<iostream>
#include<algorithm>
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

void _swap(person &a, person &b){
	struct person temp;
	temp = a;
	a = b;
	b = temp;
}

void complete(int point){
	while(point > 1){
		if(player[point-1].mark < player[point].mark){
		    _swap(player[point-1],player[point]);//如果分数低，往前排
			point--;
			continue;
			
		}
		else{
	 	    if(player[point-1].mark == player[point].mark){
	 	    	if(player[point-1].id > player[point].id){
	 	    		_swap(player[point-1],player[point]);
	 	    		point--;
	 	    	}
	 	    	else{
	 	    		break;
	 	    	}
		    }
		    else{
		    	break;
		    }
	    }	 
    }
	return; 
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
 
    sort(player+1,player+1+2*n,cmp1);
    for(int j = 1; j <= r; j++){//进行r轮比赛 
		for(int i = 1; i <= 2*n; i += 2){
    		if(player[i].power > player[i+1].power){
    			player[i].mark++;
    			//排序
    			complete(i);
    		}
    		else{
    			 player[i+1].mark++;
    			 //排序
    			 complete(i+1);   
    		} 
		}
    } 
    cout << player[q].id;
    return 0;
}
