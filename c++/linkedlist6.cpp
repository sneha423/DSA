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

int getlength(node* &head){
    node* temp=head;
    int length = 0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

// node* moveheadByk(node* &head,int k){
//     node* ptr=head;
//     while(k--){
//         ptr=ptr->next;
//     }
//     return ptr;
// }

// node* intersect(node* head1,node* head2){
//     int l1=getlength(ll1.head);
//     int l2=getlength(ll2.head);
//     node* ptr1,ptr2;

//     if(l1>l2){
//         int k=l1-l2;
//         ptr1=moveheadByk(ll1.head,k);
//         ptr2=ll2.head;
//     }
//     else-if{
//         int k=l2-l1;
//         ptr1=ll1.head;
//         ptr2=moveheadByk(ll2.head,k);
//     }
//     else{
//         ptr1=ll1.head;
//         ptr2=ll2.head;
//     }

//     while(ptr1){
//         if(ptr1==ptr2){
//             return ptr1;
//         }
//         ptr1=ptr1->next;
//         ptr2=ptr2->next;
//     }
//     return NULL;
    
    
// }

node* deletekthNodefromLast(node* &head,int k){

    node* ptr1=head;
    node* ptr2=head;
    int count=k;
    while(count--){
        ptr2=ptr2->next;
    }

    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    node* temp=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);

}

int main(){
    linkedlist ll1;
    // linkedlist ll2;
    ll1.insertatTail(1);
    ll1.insertatTail(2);
    ll1.insertatTail(3);
    ll1.insertatTail(4);
    // ll2.insertatTail(5);
    // ll2.insertatTail(4);
    // ll2.insertatTail(6);

    ll1.display();

    deletekthNodefromLast(ll1.head,3);
    ll1.display();

    // ll2.display();

    //  node* intersection=intersect(ll1.head,ll2.head);
    //     if(intersection){
    //         cout<<intersection->val<<endl;
    //     }
    //     else{
    //          cout<<"-1"<<endl;
    //     }
    // return 0;
}