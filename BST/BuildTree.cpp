//build tree from preorder and inorder
#include<iostream>
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

int search(int inarr[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inarr[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* build_tree(int prearr[],int inarr[],int start,int end){
    static int idx=0;
    if(start>end){     //invalid entry
        return NULL;
    }
    int curr=prearr[idx];
    idx++;
    Node* node=new Node(curr);
    if(start==end){     //only one element is present in inorder array
        return node;
    }
    int pos=search(inarr,start,end,curr);
    node->left=build_tree(prearr,inarr,start,pos-1);
    node->right=build_tree(prearr,inarr,pos+1,end);

    return node;
}

void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
  if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int prearr[]={1,2,4,3,5};
    int inarr[]={4,2,1,5,3};
    Node* root=build_tree(prearr,inarr,0,4);
    inorder(root);
    cout<<endl;
    preorder(root);
}