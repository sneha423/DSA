#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(3);
    pq.push(9);
    pq.push(4);
    //minimum heap
    priority_queue<int,vector<int> ,greater<int>> s;
    s.push(4);
    s.push(6);
    s.push(9);
    cout<<s.top()<<endl;
    s.push(1);
    cout<<s.top();

}