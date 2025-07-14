//case1:  dequeue operation costly
#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x){
        s1.push(x);
    }
    void pop(){
        if(s1.empty()&& s2.empty()){
            cout<<"no numbers present"<<endl;
            return;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval=s2.top();
        s2.pop();
        cout<<topval<<endl;
    }
};

int main(){
    queue q;
    q.pop();
    q.push(3);
    q.push(9);
    q.push(2);
    q.pop();
    return 0;
}