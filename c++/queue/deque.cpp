#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(9);
    dq.push_front(3);
    dq.push_front(4);
    dq.push_back(1);
    for(auto i:dq)
    cout<<i<<" ";
    cout<<"\n";
    dq.pop_back();
    dq.pop_front();
    for(auto i:dq)
    cout<<i<<" ";
    cout<<endl;
    cout<<dq.size();
    return 0;
}