#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node* parent;

Node(int val){
    data=val;
    left=right=parent=NULL;
}
Node* insert(int val){
    Node* newnode=new Node(val);
    if(newnode==NULL){
        return node(val);
    }
    if(val<newnode->data){
        Node* lchild=insert(newnode->left,val);
        newnode->left=lchild;
        lchild->parent=newnode;
    }
    else{
        Node* rchild=insert(newnode->right,val);
        newnode->right=rchild;
        rchild->parent=newnode;
    }
    return newnode;
}
};
int main(){
    Node* root=NULL;
    root=insert(50);
    insert(56);
    ins
    return 0;
}