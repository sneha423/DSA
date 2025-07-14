//given the head of a doubly linked list, delete the nodes whose neighbours have the same value.
//traverse the list from right to left
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
    bool ispalindrome(node* &head,node* &tail){
        while(head!=tail&&tail!=head->next){
            if(head->val!=tail->val){
                return false;
            }
            head=head->next;
            tail=tail->prev;
        }
        return true;
    }
};
int main(){
    doublylinkedlist dll;
    dll.insertatStart(3);
    dll.insertatStart(2);
    dll.insertatStart(1);
    dll.insertatStart(1);
    dll.insertatStart(2);
    dll.insertatStart(3);
    dll.display();
    cout<<ispalindrome(dll.head,dll.tail)<<endl;

}