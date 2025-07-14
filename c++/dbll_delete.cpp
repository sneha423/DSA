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

    void deleteatStart(){
        if(head==NULL){
            return;
        }
        node* temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }

    void deleteatEnd(){
        if(head==NULL){
            return;
        }
        node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
    }
    void deleteatKpos(int k){
        node* temp=head;
        int count=1;
        while(count<(k)){
            temp=temp->next;
            count++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
};

int main(){
    doublylinkedlist dll;
    dll.insertatStart(3);
    dll.insertatStart(5);
    dll.insertatStart(2);
    dll.display();
    // dll.deleteatStart();
    // dll.deleteatEnd();
    dll.deleteatKpos(2);
    dll.display();
   
}