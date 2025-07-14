#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

Node(int val){
    data=val;
    left=NULL;
    right=NULL;
}
};
int count(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
    return count(root->left)+count(root->right)+1;
    }
}
int sumnodes(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return sumnodes(root->left)+sumnodes(root->right)+root->data;
    }
}
int height_tree(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
    int lh=height_tree(root->left);
    int rh=height_tree(root->right);
    return max(lh,rh)+1;
    }
}
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
    int lh=height_tree(root->left);
    int rh=height_tree(root->right);
    int currdia=lh+rh+1;

    int ld=diameter(root->left);
    int rd=diameter(root->right);
    return max(currdia,max(ld,rd));
    }
}
int main(){
    Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    // root->left->right->left=new Node(8);
    cout<<count(root)<<endl;
    cout<<sumnodes(root)<<endl;
    cout<<height_tree(root)<<endl;
    cout<<diameter(root)<<endl;
    return 0;
}