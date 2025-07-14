#include<iostream>
#include<map>
using namespace std;
//map stores unique keys in sorted order
int main(){
    //diff ways to define map
    map<int,int> mp;
    //(key,value)
    map<int,pair<int,int>> m;
    map<pair<int,int>,int> p;


    mp.insert({2,3});
    mp.insert({3,3});
    mp.insert({6,1});
    mp.insert({9,2});
    mp.emplace(1,0);
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<mp[2]<<endl;   //gives the key at input pos
    cout<<mp[7]<<endl;

    auto it=mp.find(3);
    cout<<(*it).first<<endl;
    cout<<endl;
    p[{2,3}]=10;
    p.insert({{1,5},2});
    for(auto it:p){
        cout<<it.first.first<<" "<<it.second<<endl;
    }
}