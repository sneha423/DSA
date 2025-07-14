//given the head of a sorted linked list,delete all duplicants such that each element appears only once. return the linked list sorted as well
//1-1-2-3-4-4-5
//1-2-3-4-5

//2nd: print the linked list in reverse

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

void reversePrint(node* &head){
    if(head==NULL) return;//base case
    //recursive case
    reversePrint(head->next);
    cout<<head->val<<"->"<<endl;
}


void deleteRepeated(node* &head){
    node* curr_node=head;
    while(curr_node!=NULL){
        while(curr_node->next && curr_node->val==curr_node->next->val){
            node* temp=curr_node->next;
            curr_node->next=curr_node->next->next;
            free(temp);

        }
        curr_node=curr_node->next;
    }

}
int main(){

    linkedlist ll;
    ll.insertatTail(1);
    ll.insertatTail(1);
    ll.insertatTail(1);
    ll.insertatTail(2);
    ll.insertatTail(2);
    ll.insertatTail(3);
    ll.display();

    reversePrint(ll.head);
    

    deleteRepeated(ll.head);
    ll.display();

    

    return 0;
}
