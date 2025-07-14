#include<iostream>
#include<queue>

using namespace std;
int main(){
queue<pair<int,int>> q;
q.push(make_pair(2,3));
q.push(make_pair(4,5));
while(!q.empty()){
    pair<int,int> p=q.front();
    q.pop();
    cout<<"first: "<<p.first<<"   second: "<<p.second<<endl;
}
}