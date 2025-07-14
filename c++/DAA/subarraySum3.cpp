//approach 3: using divide and conquer
#include<iostream>
using namespace std;
int maximum(int a,int b,int c){
    if(a>b&&a>c){
        return a;
    }
    else if(b>a&&b>c){
        return b;
    }
    else{
        return c;
    }
}
int CrossSum(int arr[],int p,int r,int mid){
    int left_sbsum=INT8_MIN;
    int sum=0;
    for(int i=mid;i>=p;i--){
        sum=sum+arr[i];
        if(left_sbsum<sum){
            left_sbsum=sum;
        }
    }
    int right_sbsum=INT8_MIN;
    sum=0;
    for(int i=mid+1;i<r;i++){
        sum=sum+arr[i];
        if(right_sbsum<sum){
            right_sbsum=sum;
        }
    }
    return left_sbsum+right_sbsum;
}
int maxSum(int arr[],int p,int r){
    if(p==r){
        return arr[p];
    }
    int mid=(p+r)/2;
    int left_sum=maxSum(arr,p,mid);
    int right_sum=maxSum(arr,mid+1,r);
    int cross_sum=CrossSum(arr,p,r,mid);
    return maximum(left_sum,right_sum,cross_sum); 
}
int main(){
int arr[]={3,-1,1,2,3,-4};
int n=sizeof(arr)/sizeof(arr[0]);
cout<<maxSum(arr,0,n);
return 0;
}