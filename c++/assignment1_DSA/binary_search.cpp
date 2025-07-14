#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int ele,int low,int high){
    while(low<=high){
        int m=low+(high-low)/2;
        if(m==ele){
            return m;
        }
        else if (m>ele)
        {
            high=m-1;
        }
        else{
            low=m+1;
        }
        return -1;
    }
}
int main(){
    
    int arr[]={2,4,6,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    // int ele=6;
    int res=binarySearch(arr,n,6,arr[0],arr[n-1]);
    cout<<res;
}