#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next = NULL;
    }
};

void insertatHead(node* &head, int val){
    node* new_node= new node(val);
    new_node->next= head;
    head= new_node;
}

void updateatPos(node* head, int k, int val){
    node* temp= head;
    int curr_pos=0;
    while(curr_pos!=k){
        temp=temp->next;
        curr_pos++;

    }

    //temp will be pointing to kth node
    temp->data=val;
}

void deleteatPos(node* &head,int pos){
    // if(pos==0){
    //     deleteatHead(head);
    //     return;
    // }
    int curr_pos=0;
    node* prev=head;
    while(curr_pos!=pos-1){
        prev=prev->next;
        curr_pos++;
    }

    node* temp=prev->next;
    prev->next=prev->next->next;
    free(temp);
    }

//  void deleteatHead(node* &head){
//      node* temp=head;
//     head=head->next;
//      free(temp);
// }

void deleteatTail(node* &head){
    node* sec_last=head;
    while(sec_last->next->next!=NULL){
        sec_last= sec_last->next;
    }
    node* temp=sec_last->next;
    sec_last->next=NULL;
    free(temp);
}


void display(node* head){

    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    node* head=NULL;
    insertatHead(head,2);
    display(head);
    insertatHead(head,1);
    display(head);
    insertatHead(head,3);
    display(head);

    updateatPos(head,1,5);
    display(head);

    deleteatPos(head,1);
    display(head);

    // deleteatHead(head);
    // display(head);

    // deleteatTail(head);
    // display(head);

    return 0;
}