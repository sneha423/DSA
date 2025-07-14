//find the middle element of the given linked list
//concept-> slow fast pointer
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

node* middlePtr(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL&& fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

bool detectCycle(node* head){
     node* slow=head;
    node* fast=head;
    if(!head){
        return false;
    }
    while(fast&& fast->next){
        slow=slow->next;
        fast=fast->next->next;
    
    if(slow==fast){
        return true;
    }
    }
    return false;

}

int main(){

    linkedlist ll;
    // ll.insertatTail(1);
    // ll.insertatTail(7);
    // ll.insertatTail(3);
    // ll.insertatTail(8);
    // ll.insertatTail(6);
    ll.insertatTail(9);
    ll.insertatTail(4);
    ll.insertatTail(7);
    ll.insertatTail(0);
    ll.head->next->next->next=ll.head->next;
  
   
    // ll.display();
    node* middlenode=middlePtr(ll.head);
    cout<<middlenode->val<<endl;
    cout<<detectCycle(ll.head);
    return 0;
}