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
void insertAtKthPos(int val,int k){
    node* new_node=new node(val);
    node* temp=head;
    int count=1;
    while(count<(k-1)){
        temp=temp->next;
        count++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    return;
}
void updateAtKthPos(int val,int k){
    node* new_node=new node(val);
    node* temp=head;
    int count=1;
    while(count<(k-1)){
        temp=temp->next;
        count++;
    }
    temp->next->val=new_node->val;
    return;
}
}; 
int main(){
    circularLinkedList cll;
    cll.insertAtEnd(3);
    cll.insertAtEnd(7);
    cll.insertAtEnd(2);
    cll.insertAtEnd(5);
    cll.display();
    cll.insertAtKthPos(4,2);
    cll.display();
    cll.updateAtKthPos(9,2);
    cll.display();
}