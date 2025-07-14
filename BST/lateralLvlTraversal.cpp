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

void levelTraversal(Node* root,int k){
    if(root==NULL){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int lvl=0;
    int sum=0;
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(lvl==k){
                sum+=node->data;
            }
         }
            // cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        
        else if(!q.empty()){
            q.push(NULL);
            lvl++;
        }
    }
    cout<<"sum at lvl "<<k <<" is "<<sum<<endl;
}

int main(){
    Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    levelTraversal(root,2);
    return 0;
}