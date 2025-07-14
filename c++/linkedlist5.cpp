//given the head of a linked list, reverse the nodes of the list k at a time and return thre modified list
//1-2-3-4-5-6
//2-1-4-3-6-5(FOR K=2)
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

node* reverseKtimesRecursion(node* &head , int k){
    node* prev_ptr=NULL;
    node* curr_ptr=head;
    int counter=0;
    while(curr_ptr!=NULL&& counter<k){
        node* next=curr_ptr->next;
        curr_ptr->next=prev_ptr;
        prev_ptr=curr_ptr;
        curr_ptr=next;
        counter++;
    }
    if(curr_ptr!=NULL){
    node* new_head=reverseKtimesRecursion(curr_ptr,k);
    head->next=new_head;
    }
    
    return prev_ptr;
}
int main(){

    linkedlist ll;
    ll.insertatTail(1);
    ll.insertatTail(2);
    ll.insertatTail(3);
    ll.insertatTail(4);
    ll.insertatTail(5);
    ll.insertatTail(6);
    ll.display();

    ll.head=reverseKtimesRecursion(ll.head,2);
    ll.display();
}