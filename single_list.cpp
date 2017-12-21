#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Slist{
    Node *head, *last, *node;
    Slist();
    int len = 1;
    void add();
    void travell_all();

};

int main(){
	Slist beta;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		beta.add();	
	}
	
	beta.travell_all();
	return 0;
}

Slist::Slist(){
    head = NULL;
    last = NULL;
}

void Slist::add(){
    int n;
    cin >> n;
    node = new Node();
    node->data = n;

    if(last == NULL){
        head = node;
        last = node;
    }
    else{
        last->next = node;
        last = node;
    }
    len++;
}

void Slist::travell_all(){
    node = head;
    while (node!=NULL){
    cout << node->data << endl;
    node = node->next;
    }
}
