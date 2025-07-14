//similar to maps
//diff is we can store duplicate keys
#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<int,int> mp;
    mp.insert({1,2});
    mp.insert({1,3});
    auto it=mp.find(2);
    cout<<(*it).second<<endl;
    //cout<<mp[1];
}

//unoredered map
//it stores unique keys but not in any sorted order
//map functions take logarithmic time
//while unordered map generally takes constant time