#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1={1,2,3,4};
    // // auto itr=l1.begin();
    // // auto itr=l1.end(); 
     auto itr=l1.begin();
    // cout<<*itr<<endl;
     advance(itr,2);
    // cout<<*itr<<endl;
    
//     using range based loop:-
// for(auto num: l1){
//     cout<<num<<endl;
// }


//using iterators
for(auto itr=l1.begin();itr!=l1.end();itr++){
    cout<<*itr<<" ";
}
cout<<endl;
l1.insert(itr,2,9);
for(auto itr=l1.begin();itr!=l1.end();itr++){
    cout<<*itr<<" ";
}
cout<<endl;
l1.erase(itr);
for(auto itr=l1.begin();itr!=l1.end();itr++){
    cout<<*itr<<" ";
}
cout<<endl;
    return 0;
}