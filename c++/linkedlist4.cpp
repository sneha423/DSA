//given the head of a singly linked list, reverse the list, and return   the reversed list
//1-2-3-4-5
//5-4-3-2-1
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
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp= temp->next;
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

// node* reverseList(node* &head){
//     node* prevptr=NULL;
//     node* currptr= head;


//     // currptr->next=prevptr
//     // move all 3 ptrs by one step ahead

//     while(currptr!=NULL){
//         node* nextptr=currptr->next;
//         currptr->next=prevptr;
//         prevptr=currptr;
//         currptr=nextptr;

//     }
//     node* new_head=prevptr;
//     return new_head;
// }

node* reverseLLrecursion(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* new_head= reverseLLrecursion(head->next);
    head->next->next= head;
    head->next=NULL;
    return new_head;
    
}
int main(){

    linkedlist ll;
    ll.insertatTail(1);
    ll.insertatTail(2);
    ll.insertatTail(3);
    ll.insertatTail(4);
    ll.insertatTail(5);
    ll.display();

    reverseLLrecursion(ll.head);
    ll.display();
    
}
