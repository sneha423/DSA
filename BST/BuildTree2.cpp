//buildtree from postorder and inorder
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

Node* build_tree(int postarr[],int inarr[],int start,int end){
    static int idx=6;
    if(start>end){
        return NULL;
    }
    int curr=postarr[idx];
    idx--;
    Node* node=new Node(curr);
    if(start==end){
        return node;
    }
    int pos=search(inarr,start,end,curr);
    node->right=build_tree(postarr,inarr,pos+1,end);
    node->left=build_tree(postarr,inarr,start,pos-1);
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

int main(){
    int postarr[]={4,5,2,6,7,3,1};
    int inarr[]={4,2,5,1,6,3,7};
    Node* root=build_tree(postarr,inarr,0,6);
    inorder(root);

}