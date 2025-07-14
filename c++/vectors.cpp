#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> marks;
    marks={1,2,3,4};
    cout<<marks.size()<<endl;
    cout<<marks.capacity()<<endl;
    marks.resize(7);
    cout<<marks.size()<<endl;
    // marks.push_back(5);
    // marks.insert(marks.begin()+2,8);
    // marks.pop_back();
    // marks.erase(marks.begin()+1);
    marks.clear();
    for(int i=0;i<marks.size();i++){
        cout<<marks[i];
    }
    return 0;
}