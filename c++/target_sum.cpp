#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={1,2,3,6,4,8};
    int length=sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"enter target sum";
    cin>>x;
    for(int i=0;i<length;i++){
        for(int j=i+1;j<length;j++){
            for(int k=j+1;k<length;k++){
            if(arr[i]+arr[j]+arr[k]==x){
                cout<<arr[i]<<","<<arr[j]<<","<<arr[k]<<endl;
            }
        }
        }
    }
    return 0;
}