#include<iostream>
#define MAXLEN 100
using namespace std;

class stack{
int element[6];
int top=-1;

public:
bool isEmpty(){
    return(top==-1);
}
bool isFull(){
    return(top==MAXLEN-1);
}
void push(int val){
    if(isFull()){
        cout<<"overflow";
    }
    else{
        top++;
        element[top]=val;
    }
}
void pop(){
    if(isEmpty()){
        cout<<"underflow";
    }
    else{
        top--;
    }
}
void topp(){
    if(isEmpty()){
        cout<<"underflow";
    }
    else{
        cout<<element[top];
    }
}
void display(){
    for (int i=top;i>=0;i--){
        cout<<element[i]<<endl;
    }
}
};

int main(){
    stack S;
    S.push(50);
    S.push(42);
    S.display();
    S.topp();
    cout<<endl;
    S.push(90);
    S.pop();
    S.pop();
    S.topp();
    cout<<endl;
    S.display();

}