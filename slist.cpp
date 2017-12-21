#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Slist{
    Node *head, *last;
    void Create_list();
    Create_list();
    int len = 1;
    void add();
    void travell_all();

};

int main(){


}

void Slist::Create_list(){
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
    node = haed;
    
}
