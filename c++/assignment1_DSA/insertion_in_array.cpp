#include<iostream>
using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insert(int arr[],int pos,int x,int n){
    int i;
    for( i=n-1;i<=pos;i--){
        arr[i+1]=arr[i];
        arr[pos]=x;
        n++;
    }
    //  size++;
    //  arr[pos]=x;
    display(arr,n++);
}

int main(){
    int arr[]={1,5,6,5,0,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insert(arr,3,9,n);
    return 0;
}