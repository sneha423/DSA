#include<iostream>
using namespace std;

int firstOcc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstOcc(arr,n,i+1,key);
}

int lastOcc(int arr[],int n,int i,int key){
    int restarr=lastOcc(arr,n,i+1,key);
    if(restarr!=1){
        return restarr;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}

int main(){

    int arr[]={1,2,4,6,2,7};
    int key;
    
    cout<<firstOcc(arr,5,0,2)<<endl;
    cout<<lastOcc(arr,5,0,2);
    
}