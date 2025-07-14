#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* prev;
Node* next;
Node(int val){
    data=val;
    prev=NULL;
    next=NULL;
}
};
class DLL{
public:
Node* head;
DLL(){
    head=NULL;
}
void insertatBgn(int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head=newnode;
        // newnode->next=head;
        // head->prev=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insertatEnd(int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head=newnode;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void insertAfterValue(int num,int val){
    Node* newnode= new Node(num);
    if(head==NULL){
        cout<<"list empty";
        head=newnode;
    }
    else{
        Node* temp=head;
        while(temp!=NULL&&temp->data!=val){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"value not present"<<endl;
            insertatEnd(num);
        }
        else if(temp->next==NULL){
        temp->next=newnode;
        newnode->prev=temp;
        }
        // else if(temp->data!=val){
        //     cout<<"value not found";
        // // temp->next=newnode;
        // // newnode->prev=temp;
        // }
        else{
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next->prev=newnode;
        temp->next=newnode;
        }
        
    }   
}
void deleteatBgn(){
     Node* temp=head;
     head=head->next;
    if(head==NULL){
        cout<<"list empty";
    }
    else{
       
        head->prev=NULL;
    }
    delete temp;
}
void deleteatEnd(){
    Node* temp=head;
    if(head==NULL){
        cout<<"list empty";
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        if(temp->prev){
        temp->prev->next=NULL;
        }
        else{
            head=NULL;
        }
    }
    delete temp;
}
void deleteSpecific(int val){
    Node* temp=head;
    if(head==NULL){
        cout<<"list empty";
        return;
    }
    else {
        while(temp->data!=val){
            temp=temp->next;
        }
        if(temp->data!=val){
            cout<<"  bj";
        }
        else if(temp==head){
            head=head->next;
            head->prev=NULL;
        }
        else if(temp->next==NULL){
            temp->prev->next=NULL;
        }
        else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
        delete temp;
        return;
    }
    
}
void print(){
    Node* temp=head;
    if(head==NULL){
        cout<<"list empty";
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
}

};
int main(){
    DLL d1;
     d1.insertatBgn(3);
     d1.insertatEnd(4);
    d1.insertatEnd(5);
    d1.insertAfterValue(1,4);
    d1.print();
    // d1.deleteatBgn();
    // d1.print();
    // d1.deleteatEnd();
    // d1.print();
    d1.deleteSpecific(0);
    d1.print();
    return 0;
}