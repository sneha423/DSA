#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if (arr[i]==key){
            return i+1;
        }
            return -1; 
    }
}

int main(){
    int n;
    cout<<"enter size of array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"enter no to find";
    cin>>key;
    cout<<linearSearch(arr,n,key);
    return 0;
}