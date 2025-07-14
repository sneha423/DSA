#include<iostream>
#include<vector>
using namespace std;
    //note:
    // in vector emd points to the memmory location
    // right after the last elemnent
    // and back points to the last element
int main(){
    vector<int> v;
    v.push_back(3);            //3
    v.emplace_back(5);         //3,5
    
    vector<int> v1(5,20);
    vector<int> v2(v1);    // just a copy of v1

    //insertion in vector
    vector<int>::iterator it=v.begin();   //long way to write iterator
    for(auto it=v2.begin();it!=v2.end();it++){   //loop to print vector using iterator
        cout<<*(it)<<" ";
    }

    for(auto it:v){
        cout<<it<<" ";
    }

    cout<<v.back()<<endl;

    //deletion in vector
    v.erase(v.begin()+1);
    for(auto it:v){
        cout<<it<<" "<<endl;
    }
    v.insert(v.begin(),10);
    v.insert(v.begin()+1,3,30);
    //(start pos to insert , no of repetions)
    cout<<v.size()<<endl;
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    v.erase(v.begin()+1,v.begin()+3);   
    //(start pt of deletion, right after last deletion)

    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    v.swap(v2);
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:v2){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<v.empty();
    cout<<endl;

    //pair inside vector
    vector<pair<int,int>> b;
    b.insert(b.begin(),{2,3});
    b.push_back({6,7});
    for(auto it:b){
        cout<<it.first<<" ";
    }

    //lower bound means value should not be less than key
    //upper bound means value should be greater than key(equal nhi hoga)
    
}