#include<iostream>
#include<algorithm>
using namespace std;
void swap(int A[],int i,int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}
int partition(int A[],int l,int r){
    int x=A[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(A[j]<=x){
            i++;
            swap(A,i,j);
        }
    }
    swap(A,i+1,r);
    return i+1;
}
void Quicksort(int A[],int p,int r){
    if(p<r){
        int q=partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}
int main(){
    int arr[]={2,5,3,7,9,1,6,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    Quicksort(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}