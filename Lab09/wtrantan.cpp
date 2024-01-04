#include<iostream>
#include <deque>
#include<queue>
#include<string>
using namespace std;


struct  Node {
    char letter;
    double freq;
    Node* left;
    Node* right;  
};

struct nodeleast_to_Greatest {
    bool operator()(Node* left, Node* right){
        return (left->freq > right->freq);
    }
};

priority_queue<Node *, deque<Node *>, nodeleast_to_Greatest> Q;


Node* Getnew(char letter, double freq){
    Node* newnode= new Node();
    newnode->freq=freq;
    newnode->letter=letter;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
    
}
Node* empty(){
    Node* temp= new Node();
    temp->left=NULL;
    temp->right=NULL;
    temp->letter='\0';
    temp->freq=0;
    return temp;
}

static void encode(Node *Q, string en, int i,string enc[]) {
    char letters[]={'A','B','C','D','E','F'};
    if (Q==NULL) {
        return;
    }
    if (Q->letter == letters[i]) {
        enc[i] = en;
    }
    if (Q->letter!= letters[i]){
    encode(Q->left, en + "0", i, enc);
    encode(Q->right, en + "1", i, enc);
    }
};

void huffmanCode(){
   Node *x= empty();
    Node *y= empty();
    Node *z=empty();
    for(int k=0; k<5;k++){
        x = Q.top();
        Q.pop();
        y = Q.top();
        Q.pop();
        z = Getnew(' ', (x->freq + y->freq));
        z->left = x;
        z->right = y;
        Q.push(z);
    }
}


int main(){
    double freq;
    char letters[]={'A','B','C','D','E','F'};
    string enc[6];
    int x=0;
    while (x!=6){
        cin>>freq;
        if (x==0){
            Q.push(Getnew('A', freq));
        }
        if (x==1){
            Q.push(Getnew('B', freq));
        }
        if (x==2){
            Q.push(Getnew('C', freq));
        }
        if (x==3){
            Q.push(Getnew('D', freq));
        }
        if (x==4){
            Q.push(Getnew('E', freq));
        }
        if (x==5){
            Q.push(Getnew('F', freq));
        }
        x++;
    }
    huffmanCode();
    for (int i = 0; i < 6; i++) {
        encode(Q.top(), "",i, enc);
    }
    for (int i = 0; i < 6; i++){
        cout<<letters[i]<<":"<<enc[i]<<endl;
    }
}