#include<iostream>
#include<set>
using namespace std;
//stores in a sorted order
//elements are sorted and unique
int main(){
set<int> s;
s.insert(4);
s.insert(7);
s.emplace(5);
auto it=s.find(3); // return an iterator which pts to pos where 3 is stored
for(auto it:s){
    cout<<it<<" ";
}
cout<<endl;
cout<<s.count(7)<<endl;// counts the no of times a specific value is in the set

s.erase(s.find(4),s.find(7));  //[first,last)
for(auto it:s){
    cout<<it<<" ";
}

}