#include<iostream>
using namespace std;
int main(){
    pair<int,int> p={1,3};
    cout<<p.first<<endl;
    cout<<p.second<<endl;
    pair<int,pair<int,int>> m={1,{3,4}};
    //p.swap();
    cout<< m.first<<endl;
    cout<<m.second.second<<endl;
    pair<char,int> s[]={{'a',1},{'b',2},{'c',3}};
    cout<<s[1].first;
}