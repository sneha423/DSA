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
    }
    while(temp!=head);
    cout<<endl;
}
void insertAtEnd(int val){
    node* new_node=new node(val);
    if (head==NULL){
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
void deleteAtStart(){
    if(head==NULL){
        return;
    }
    node* temp=head;
    node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    
    head=head->next;
    tail->next=head;
    free(temp);
} 
void deleteAtEnd(){
    if(head==NULL){
        return;
    }
    node* tail=head;
    while(tail->next->next!=head){
        tail=tail->next;
    }
    node* temp=tail->next;
    tail->next=head;
    free(temp);
}
void deleteAtKthPos(int k){
    node* temp=head;
    int count=1;
    while(count<(k)){
        temp=temp->next;
    }
    temp=temp->next;
    temp->next=temp->next->next;
    free(temp);
    
}
};

int main(){
    circularLinkedList cll;
    cll.insertAtEnd(4);
    cll.insertAtEnd(8);
    cll.insertAtEnd(2);
    cll.display();
    cll.deleteAtStart();
    cll.display();
    cll.deleteAtEnd();
    cll.display();
    cll.insertAtEnd(3);
    cll.insertAtEnd(2);
    cll.insertAtEnd(9);
    cll.display();
    cll.deleteAtKthPos(3);
    cll.display();
    return 0;
}