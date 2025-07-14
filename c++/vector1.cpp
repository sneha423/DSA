#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vector<int> v;
    // v={1,2,5,4,5,6};

    // int x;
    // cout<<"enter x";
    // cin>>x;
    // int occ=0;
    // for(int i=0;i<v.size();i++){
    //     if(v[i]==x){
    //         occ++;
    //     }
    // }

    // cout<<occ;
    
    int arr[]={1,4,6,7,8};
    int sum=0;
    for(int i=0;i<5;i++){
        if(i%2==0){
            sum=sum+arr[i];
        }
        else{
            sum=sum-arr[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}