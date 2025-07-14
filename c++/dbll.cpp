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
};
void deleteSameNeighbour(node* &head,node* &tail){
    node* curr= tail->prev;
    while(curr!=head){
        node* prev=curr->prev;
        node* next=curr->next;
        if(prev->val==next->val){
            prev->next=next;
            next->prev=prev;
            free(curr);
    }
        curr=prev;
    }
}
int main(){
    doublylinkedlist dll;
    dll.insertatStart(1);
    dll.insertatStart(2);
    dll.insertatStart(1);
    dll.insertatStart(4);
    dll.insertatStart(1);
    dll.insertatStart(5);
    dll.insertatStart(7);

    dll.display();
    deleteSameNeighbour(dll.head,dll.tail);
    dll.display();
}