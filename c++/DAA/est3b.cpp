#include<iostream>
#include<stack>
using namespace std;
class SpcStack{
    public:
    stack<int> Mainst;
    stack<int> Minst;

    void push(int x){
        Mainst.push(x);
        if(Minst.empty()||x<Minst.top()){
            Minst.push(x);
        }
    }

    void pop(){
        int ele=Mainst.top();
        if(ele==Minst.top()){
            Minst.pop();
        }
        Mainst.pop();
    }

    void print(){
        stack<int> tempMain = Mainst;
        stack<int> tempMin = Minst;
        cout<<"mainstack: "<<endl;
        while(!tempMain.empty()){
            cout<<tempMain.top()<<" ";
            tempMain.pop();
        }
        cout<<endl;
        cout<<"minstack: "<<endl;
        while(!tempMin.empty()){
            cout<<tempMin.top()<<" ";
            tempMin.pop();
        }

    }

    void getmin(){
        cout<<endl;
        if(!Minst.empty()){
        cout<<"min element: "<<Minst.top()<<endl;
        }
        else{
            cout<<"minstack is empty"<<endl;
        }
    }
};

int main(){
    SpcStack s;
    s.push(10);
    s.print();
    s.getmin();
    s.push(15);
    s.print();
    s.getmin();
    s.push(2);
    s.print();
    s.getmin();
    s.pop();
    s.print();
    s.getmin();
}