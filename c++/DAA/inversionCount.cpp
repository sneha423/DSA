#include<iostream>
using namespace std;
int merge(int arr[],int l,int q,int r){
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
    int res=0;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            res+=(n1-i);
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
    return res;
}
int mergesort(int arr[],int l,int r){
    int res=0;
    if(l<r){
   
        int q=(l+r)/2;
        res+=mergesort(arr,l,q);
        res+=mergesort(arr,q+1,r);
        res+=merge(arr,l,q,r);
    }
    return res;
}
int main(){
    int arr[]={2,4,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<mergesort(arr,0,n-1);
    return 0;
}