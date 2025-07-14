#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class CLL{
    public:
    Node* head;
    CLL(){
        head=NULL;
    }
    void insertEnd(int val){
        Node* newnode=new Node(val);
        Node* temp=head;
        if(head==NULL){
            head=newnode;
            newnode->next=head;
        }
        else{
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
        }
    }
    void display(){
        if(head==NULL){
            cout<<"list empty";
        }
        else{
            Node* temp=head;
            while(temp->next!=head){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data;
        }
    }
    void divide(){
        Node* head1=head;
        Node* head2=head;
        while(head2->next!=head&&head2->next->next!=head){
            head1=head1->next;
            head2=head2->next->next;
        }
        // if(head2->next->next==head){
        //     head2=head2->next;
        // }
        Node* sechalf=head1->next;
        head1->next=head;
        head2->next=sechalf;
        Node* curr=head;
        do{
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        while(curr!=head);
        cout<<endl;
        curr=sechalf;
        do{
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        while(curr!=sechalf);
        cout<<endl;
    }
//         while(curr->next!=head1){
//             cout<<curr->data<<" ";
//             curr=curr->next;
//         }
//         cout<<curr->data;
//         Node* curr2=sechalf;
//         while(curr2->next!=sechalf){
//             cout<<curr2->data<<" ";
//             curr2=curr2->next;
//         }
//         cout<<curr2->data;
//     }
 };
int main(){
    CLL c1;
    c1.insertEnd(5);
    c1.insertEnd(8);
    c1.insertEnd(3);
    c1.insertEnd(5);
    c1.insertEnd(0);
    c1.display();
    cout<<endl;
    c1.divide();
    return 0;
}