#include<iostream>
#include<vector>

using namespace std;
int main(){

    vector<int> v;
    v={1,2,3,4,5};
    int k=3;
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());

    for(int a:v){
        cout<<a<<" ";
    }
    cout<<endl;
    // int new_arr[length];
    // int j=0;

    // for(int i=length-k;i<length;i++){
    //     new_arr[j++]=arr[i];
    // }
    // for(int i=0;i<=k;i++){
    //     new_arr[j++]=arr[i];
    // }
    // for(int j=0;j<length;j++){
    //     cout<<new_arr[j]<<" ";
    // }
    // cout<<endl;

    return 0;
}