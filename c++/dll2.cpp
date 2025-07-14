//a critical pt in a linked list is defined as either a local maxima/local minima.
//given the tail of a linked list return an array of length 2 containing [min dis,max dis]

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

bool isCriticalPt(node* currNode){
    if(currNode->prev->val<currNode->val && currNode->next->val<currNode->val){
        return true;
    }
    if(currNode->prev->val>currNode->val && currNode->next->val>currNode->val){
        return true; 
    }
    else{
        return false;
    }
}

vector<int> disbwCriticalPts(node* &head,node* &tail){
     vector<int> ans(2,INT_MAX);
    int firstCP=-1,lastCP=-1;

    node* currNode=tail->prev;
    if(currNode==NULL){
        ans[0]=ans[1]=-1;
        return ans;
    }
    int currPos=0;
    while(currNode->prev!=NULL){
        if(isCriticalPt(currNode)){
            if(firstCP==-1){
                firstCP=lastCP=currPos;
            }
            else{
                ans[0]=min(ans[0],currPos-lastCP);
                ans[1]=currPos-firstCP;
                lastCP=currPos;

            }
        }
        currPos++;
        currNode=currNode->prev;

    }
    if(ans[0]==INT_MAX){
        ans[0]=ans[1]=-1;
    }
    return ans;
}

int main(){
    doublylinkedlist dll;
    // dll.insertatStart(3);
    dll.insertatStart(1);
    dll.insertatStart(5);
    dll.insertatStart(2);
    dll.insertatStart(6);
    dll.insertatStart(3);
    dll.display();
    vector<int> ans=disbwCriticalPts(dll.head,dll.tail);
    cout<<ans[0]<<" "<<ans[1]<<endl;

}