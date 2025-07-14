// divide and conquer approach
// tell the index of maximum element 
// but the first and last elements can't be the peak
#include<iostream>
using namespace std;
int peakIndex(int arr[],int l,int h){
    
    while(l<h){
    int mid=(l+h)/2;
    if(l==h){
        return l;
    }
    if(arr[mid]<arr[mid+1]){
        l=mid+1;
        //cout<<"l: "<<l<<endl;
    }
    else{
        h=mid;
        // cout<<"h: "<<h<<endl;
    }
    }
    // return l;
}
int main(){
    int arr[]={1,5,9,4,3,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<peakIndex(arr,1,n-2);
    return 0;
}