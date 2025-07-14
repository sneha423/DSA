#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

node(int val){
    data=val;
    left=NULL;
    right=NULL;
}
};
int search(node* root,int k){
    if(root==NULL||root->data==k){
        return root->data;
    }
    if(root->data<k){
        return search(root->left,k);
    }
    else return search(root->right,k);
}
int main(){
    node* root= new node(60);
    root->left=new node(41);
    root->right=new node(74);
    root->left->left=new node(16);
    root->left->right=new node(53);
    root->right->left=new node(65);
    root->right->right=new node(78);
    int ans=search(root,74);
    cout<<ans;
    return 0;
}