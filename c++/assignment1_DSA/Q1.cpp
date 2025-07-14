// do insertion if ele not found,using binary search
#include<iostream>
using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int binarySearch(int arr[],int n,int ele,int low,int high){
    bool check=0;
    while(low<high){
        int m=low+(high-low)/2;
        if(arr[m]==ele){
            return m;
            check=1;
        }
        else if (arr[m]>ele)
        {
            high=m-1;
        }
        else
        {
            low=m+1;
        }
        
    }
    if(check==0){
        cout<<"research unsuccessful";
    }
    
}
int main(){
    int arr[]={1,3,4,5,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int res=binarySearch(arr,n,10,0,n);
    cout<<res+1;
    return 0;
}