// given the head of a linked list, group all the nodes with odd indies together followed by the nodes with even indices and return the reordered list
// 1-2-3-4-5-6
// 1-3-5-2-4-6
// steps:
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
    node* new_node= new node(value);
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

node* oddevenLinkedlist(node* &head){

    node* evenhead=head->next;
    node* oddptr=head;
    node* evenptr=evenhead;

    while(evenptr&& evenptr->next){
        oddptr->next=oddptr->next->next;
        evenptr->next=evenptr->next->next;
        oddptr=oddptr->next;
        evenptr=evenptr->next;
    }
    oddptr->next=evenhead;
    return head;
}

int main(){
    linkedlist ll;
    ll.insertatTail(1);
    ll.insertatTail(2);
    ll.insertatTail(3);
    ll.insertatTail(4);
    ll.insertatTail(3);
    ll.insertatTail(2);
    ll.insertatTail(1);
    ll.display();
    ll.head=oddevenLinkedlist(ll.head);
    ll.display();

}    
