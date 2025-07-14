//same as vector but includes front functions as well
#include<iostream>
#include<list>
using namespace std;
int main(){
list<int> l;
l.emplace_front(5);
l.push_front(7);
for(auto it:l){
    cout<<it<<" ";
}
cout<<endl;
}