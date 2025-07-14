#include<iostream>
using namespace std;

class node{
public:
int val;
node* prev;
node* next;

    node(int data){
        val=data;
        prev=NULL;
        next=NULL;

    }
};
class doublylinkedlist{
public:
node* head;
node* tail;

    doublylinkedlist(){
        head=NULL;
        tail=NULL;

    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insertatStart(int val){
        node* new_node=new node(val);

        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }

        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
    }

    void insertatEnd(int val){
        node* new_node=new node(val);
        if(tail==NULL){
            tail=new_node;
            head=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
    }

    void insertatKpos(int val,int k){
        node* new_node=new node(val);
        node* temp=head;
        int count=1;
        while(count<(k-1)){
            temp=temp->next;
            count++;
        }
        new_node->next= temp->next;
        temp->next=new_node;

        new_node->prev=temp;
        new_node->next->prev=new_node;
        return;

    }
};


int main(){
    // node* new_node=new node(3);
    doublylinkedlist dll;
    // dll.head=new_node;
    dll.insertatStart(1);
    dll.insertatStart(2);
    dll.insertatStart(3);
    dll.display();
    dll.insertatEnd(3);
    dll.insertatEnd(5);
    dll.insertatEnd(7);
    dll.display();
    dll.insertatKpos(9,4);
    dll.display();

    return 0;

}