#include<iostream>
#include<set>
using namespace std;
//here elements are sorted but not unique 
int main(){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    for(auto it:ms){
        cout<<it<<" ";
    }
    cout<<endl;
    //ms.erase(ms.find(1));
    ms.erase(ms.find(1),ms.upper_bound(1));
    for(auto it:ms){
        cout<<it<<" ";
    }
}

// this stores unique elements but not sorted
//lower_bound and upper_bound does not work
unordered_set<int> us;
