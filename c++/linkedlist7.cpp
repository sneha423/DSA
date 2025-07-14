//merge two sorted lingly linked lists

#include<iostream>
using namespace std;
 
class node{
    public:
    int val;
    node* next;

    node(int data){
        val=data;
        next=NULL;
    }
};

class linkedlist{
public:
    node* head;
    linkedlist(){
        head=NULL;
    }

    void insertatTail(int value){
        node* new_node=new node(value);
        if(head==NULL){
            head=new_node;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }

    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
    }
    cout<<"NULL"<<endl;
    }
};

node* mergeList(node* &head1,node* &head2){

    node* dummyHeadNode=new node(-1);
    node* ptr1=head1;
    node* ptr2=head2;
    node* ptr3=dummyHeadNode;

    while(ptr1&&ptr2){
        if(ptr1->val<ptr2->val){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
     
     if(ptr1){
        ptr3->next=ptr1;
     }
     else{
        ptr3->next=ptr2;
     }

     return dummyHeadNode->next;
}

int main(){
    linkedlist ll1;
    linkedlist ll2;

    ll1.insertatTail(1);
    ll1.insertatTail(4);
    ll1.insertatTail(5);
    ll2.insertatTail(2);
    ll2.insertatTail(3);
    
    linkedlist ll3;
    ll3.head=mergeList(ll1.head,ll2.head);
    ll3.display();
    return 0;
}