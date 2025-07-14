// given the head of a linked list,rotate the list to right by k places
// steps:
// 1-> find n
// 2->find tail node,
// 3->tail->next=head
// 4->traverse n-k nodes,
// n-k->next=NULL
// n-k+1=newhead
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
node* rotatetoRightbyK(node* &head,int k){
    int n=0;
    node* tail=head;

    while(tail->next){
        n++;
        tail=tail->next;
    }
    n++;//for including last node
    k= k%n;
    if(k==0){
        return head;
    }
    tail->next=head;
    node* temp=head;
    for(int i=1;i<n-k;i++){
        temp=temp->next;
    }
    //now temp is pointing to n-kth node
    node* newhead=temp->next;
    temp->next=NULL;
    return newhead;


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
    ll.head=rotatetoRightbyK(ll.head,4);
    ll.display();

}    