#include<iostream>
using namespace std;
int maximum(int a,int b,int c){
    return max(max(a,b),c);
}
// int subProfit(int arr[],int p,int r){
//     int pr=0;
//     for(int i=p;i<=r;i++){
//         for(int j=i+1;j<=r;j++){
//             if((arr[j]-arr[i])>pr){
//                 pr=(arr[j]-arr[i]);
//             }
//         }
//     }
//     return pr;
// }
int crossProfit(int arr[],int p,int r,int mid){
    int m=arr[p];
    int n=arr[mid+1];
    for(int i=p;i<=mid;i++){
        m = min(m, arr[i]);
        cout<<"m: "<<m<<endl;
    }
    for(int i=mid+1;i<=r;i++){
        n=max(n,arr[i]);
        cout<<"n: "<<n<<endl;
    }
    int cpr=n-m;
    return cpr;
}
int maxProfit(int arr[],int p,int r){
    
    if(p==r){
        return 0;
    }
    int mid=(p+r)/2;
    int left_sbpr=maxProfit(arr,p,mid);
    cout<<"left subarray profit: "<<left_sbpr<<endl;
    int right_sbpr=maxProfit(arr,mid+1,r);
    cout<<"right subarray profit: "<<right_sbpr<<endl;
    int cross_pr=crossProfit(arr,p,r,mid);
    cout<<"cross profit: "<<cross_pr<<endl;
    return maximum(left_sbpr,right_sbpr,cross_pr);
}
int main(){
    int arr[]={2,1,5,2,2,6,7,1,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"final max profit: "<<maxProfit(arr,0,n-1);
    return 0;
}