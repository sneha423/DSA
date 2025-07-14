//check if the linked list is a palindrome

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

bool isPalindrome(node* &head){
    //find the middle element
     node* slow=head;
    node* fast=head;
    while(fast!=NULL&& fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    //break linked list in middle
    node* curr=slow->next;
    node* prev=slow;
    slow->next=NULL;

    //reverse second-half of the linked list
    while(curr){
        node* nextnode=curr->next;
        curr->next=prev;
        prev=prev->next;
        curr= nextnode;

    }
    //check if the two linked lists are equal?
    node* head1=head;
    node* head2=prev;
    while(head2){
        if(head1->val!=head2->val){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;

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
    cout<<isPalindrome(ll.head)<<endl;

}