// given the head of a linked list, delete ebery alternate element from the list starting from the second element
//1-2-3-4-5-6
//1-3-5

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
            head= new_node;
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
        }cout<<"NULL"<<endl;
    }
};

void deleteAltNodes(node* &head){

    node* curr_node=head;
    while(curr_node!=NULL && curr_node->next!=NULL){
        node* temp=curr_node->next;
        curr_node->next=curr_node->next->next;
        free(temp);
        curr_node=curr_node->next;
    }
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

    deleteAltNodes(ll.head);
    ll.display();
    return 0;
}