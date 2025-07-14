#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4};
    cout<<sizeof(arr)<<endl;
    int length=sizeof(arr)/sizeof(arr[0]);
    int x;
    cin>>x;
    for(int ind=0;ind<length;ind++){
        if(arr[ind]==x){
            cout<<ind<<endl;
        }
        else{
            return -1;
        }
    }
    int sum=0;
    for(int ind=0;ind<length;ind++){
        sum= sum+arr[ind];
    }
     cout<<sum<<endl;
     int max=arr[0];
    for(int ind=0;ind<length;ind++){
        if(arr[ind]>max){
            max=arr[ind];
        }
    }
    cout<<max;
   
}