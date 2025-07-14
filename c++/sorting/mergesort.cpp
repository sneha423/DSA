#include<iostream>
using namespace std;
void merge(int arr[],int l,int q,int r){
    //creating subarrays
    int n1=q-l+1;
    int n2=r-q;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
         L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[q+1+j];
    }

    //merging subarrays in sorted manner
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
        int q=(l+r)/2;
        mergesort(arr,l,q);
        mergesort(arr,q+1,r);
        merge(arr,l,q,r);
}

int main(){
    int arr[]={1,4,2,5,3,6,8,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}