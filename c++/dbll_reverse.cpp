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
    void* reverse(node* &head,node* &tail){
        node* curr=head;
        while(curr){
            node* next=curr->next;
            curr->next=curr->prev;
            curr->prev=next;
            curr=next;
        }
        node* newhead=tail;
        tail=head;
        head=newhead;

    }
    
};

int main(){
    doublylinkedlist dll;
    dll.insertatStart(3);
    dll.insertatStart(5);
    dll.insertatStart(2);
    dll.display();
    dll.reverse(dll.head,dll.tail);
    dll.display();
}