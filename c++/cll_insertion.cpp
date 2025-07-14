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
class circularLinkedList{
public:
node* head;
circularLinkedList(){
    head=NULL;
}
void display(){
     node* temp=head;
    
   do{
    cout<<temp->val<<" ";
    temp=temp->next;
   }while(temp!=head);
   cout<<endl;
}
void insertAtStart(int val){
    node* new_node=new node(val);
    if(head==NULL){
        head=new_node;
        new_node->next=head;
        return;
    }
    node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=new_node;
    new_node->next=head;
    head=new_node;
}
void insertAtEnd(int val){
    node* new_node=new node(val);
    if(head==NULL){
        head=new_node;
        new_node->next=head;
        return;
    }
    node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=new_node;
    new_node->next=head;
}
};



int main(){
    circularLinkedList cll;
    cll.insertAtStart(5);
    cll.insertAtStart(3);
    cll.insertAtStart(5);
    cll.insertAtStart(7);
    cll.insertAtStart(1);
    cll.display();
    cll.insertAtEnd(4);
    cll.insertAtEnd(5);
    cll.insertAtEnd(6);
    cll.insertAtEnd(7);
    cll.display();
}