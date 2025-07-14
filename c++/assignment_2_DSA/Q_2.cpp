#include<iostream>
using namespace std;

int missingNo(int arr[],int l){
    int mid=l/2;
    for(int i=0;i<l;i++){
        if(arr[mid]!=mid-1&& arr[mid-1] ==mid){
            break;
        }
        else{
            mid=mid+1;
        }
    }
    return mid+1;
}

int main(){
    int arr[]={1,2,3,5,6,7};
    int l=sizeof(arr)/sizeof(arr[0]);
    int ele=missingNo(arr,l);
    cout<<ele;
}