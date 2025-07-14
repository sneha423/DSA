// approach 2 : Brute force using 2 loops
//do the sum in horizontal way
#include<iostream>
using namespace std;
int subarrSum(int arr[],int n){
    int ans=INT8_MIN;
    for(int index=0;index<n;index++){
        int sum=0;
        for(int size=1;size<=n;size++){
            if(index+size>n){
                break;
            }
            sum=sum+arr[size+index-1];
            if(ans<sum){
                ans=sum;
            }
        }
    }
    return ans;
}
int main(){
    int arr[]={-1,3,5,-8,10,-4,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subarrSum(arr,n);
    return 0;
}