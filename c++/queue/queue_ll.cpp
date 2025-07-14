#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data=val;
        next=NULL;
    }
    
};
class queue{
node* front;
node* back;
public:
queue(){
    front=back=NULL;
}
void push(int x){
    node* n=new node(x);
    if(front==NULL){
        back=n;
        front=n;
        return;
    }
    back->next=n;
    back=n;
}
void pop(){
    if(front==NULL){
        cout<<"queue underflow"<<endl;
        return;
    }
    node* todel=front;
    front=front->next;
    delete todel;
}
int peek(){
    if(front==NULL){
        cout<<"queue underflow"<<endl;
        return -1;;
    }
    return front->data;
}
};
int main(){
    queue q;
    cout<<q.peek()<<endl;
    q.pop();
    q.push(2);
    cout<<q.peek()<<endl;
    q.push(0);
    q.pop();
    cout<<q.peek()<<endl;

    return 0;
}