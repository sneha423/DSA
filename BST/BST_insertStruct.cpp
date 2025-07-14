#include<iostream>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insert(node* root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left= insert(root->left,val);
    }
    else{
        root->right= insert(root->right,val);
    }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* search(node* root,int key){
    if(root==NULL){
        cout<<"key not found";
        return NULL;
        
    }
    if(root->data==key){
        cout<<"key exists";
        return root;
    }
    if(root->data>key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
node* inordersucc(node* root){
    node* curr=root;
    while(curr&& curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node* deleteBST(node* root,int val){
    // cases:
    // 1-> given node has no child(leaf node)
    // 2-> given node has one child
    // 3-> given node has two children

    if(val<root->data){
        root->left=deleteBST(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteBST(root->right,val);
    }
    else{
        if(root->left==NULL){
           node* temp=root->right;
           free(root);
           return temp;
        }
        else if(root->right==NULL){
           node* temp=root->left;
           free(root);
           return temp;
        }
        node* temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=deleteBST(root->right,temp->data);
    }
    return root;
}

int main(){
    node* root=NULL;
    root=insert(root,50);
    insert(root,34);
    insert(root,67);
    insert(root,45);
    insert(root,65);
    inorder(root);
    cout<<endl;
    search(root,67);
    deleteBST(root,67);
    cout<<endl;
    inorder(root);
    cout<<endl;
    search(root,45);

    return 0;
}