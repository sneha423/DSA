// approach 1: Brute force using 3 loops
#include<iostream>
using namespace std;
int subarrSum(int arr[],int n){
    int ans=INT8_MIN;
    for(int size=1;size<=n;size++){
        for(int index=0;index<n;index++){

            int sum=0;
            if(index+size>n){
                break;
            }
            for(int k=index;k<(index+size);k++){
                sum=sum+arr[k];
                if(ans<sum){
                    ans=sum;
                }
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