// case1:  making push method costly
#include<iostream>
#include<queue>
using namespace std;

class stack{
int N;
queue<int> q1;
queue<int> q2;
public:
stack(){
    N=0;
}
void push(int x){
    q2.push(x);
    N++;
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    // queue<int> temp=q1;
    // q1=q2;
    // q2=temp;
}
void pop(){
    if(q1.empty()){
        cout<<"stack is empty"<<endl;
        return;
    }
    cout<<q1.front()<<endl;
    q1.pop();
    N--;
}
};

int main(){
    stack s;
    s.pop();
    s.push(8);
    s.push(2);
    s.push(4);
    s.pop();
    s.push(1);
    s.pop();
    return 0;
}