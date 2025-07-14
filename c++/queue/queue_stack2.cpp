//case2:  making enqueue operation costly
#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;
    public:
    void pop(){
        if(s1.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        cout<<s1.top()<<endl;
        s1.pop();
    }
    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
};

int main(){
    queue q;
    q.pop();
    q.push(3);
    q.push(9);
    q.push(2);
    q.pop();
    q.pop();
    

    return 0;
}

