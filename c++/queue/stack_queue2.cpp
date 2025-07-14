// case2:  making pop function costly
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
    q1.push(x);
    N++;
}
void pop(){
    if(q1.empty()){
        cout<<"stack is empty"<<endl;
        return;
    }
    while(q1.size()!=1){
        q2.push(q1.front());
        q1.pop();
    }
    cout<<q1.front()<<endl;
    q2.push(q1.front());
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }

    // queue<int> temp=q1;
    // q1=q2;
    // q2=temp;
}
// int top(){
//     if(q1.empty()){
//         return -1;
//     }
//     while(q1.size()!=1){
//         q2.push(q1.front());
//         q1.pop();

//     }
//     int ans=q1.front();
//     q2.push(ans);

//     queue<int> temp=q1;
//     q1=q2;
//     q2=temp;

//     return ans;
// }
};

int main(){
    stack s;
    s.pop();
    //cout<<s.top()<<endl;
    s.push(8);
    s.push(2);
    s.push(4);
    s.pop();
    // cout<<s.top()<<endl;
    s.push(1);
    s.pop();
    // cout<<s.top()<<endl;
    return 0;

}