// given the head of a doubly linked list. the values of the 
// linked list are sorted in increasing order.
// find if there exists a pair of distinct nodes such that sum of their values is x.
// return the pair in the form of [l,r] where l and r are the values stored in the 2 node pointed by pointers.
// if there are multiple pairs return any of them.
// if there is no such pair return [-1,-1]
#include<iostream>
#include<vector>
#include<climits>
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

vector<int> pairSum(node* &head,node* &tail,int x){
    vector<int> ans(2,-1);
    while(head!=tail){
        int sum= head->val+tail->val;
        if(sum==x){
            ans[0]=head->val;
            ans[1]=tail->val;
            return ans;
        }
        if(sum>x){
            tail=tail->prev;
        }
        else{
            head=head->next;
        }
    }
    return ans;
}

int main(){
    doublylinkedlist dll;
    // dll.insertatStart(3);
    dll.insertatStart(11);
    dll.insertatStart(9);
    dll.insertatStart(6);
    dll.insertatStart(5);
    dll.insertatStart(1);
    dll.display();
    vector<int> ans=pairSum(dll.head,dll.tail,11);
    cout<<ans[0]<<" "<<ans[1]<<endl;

}