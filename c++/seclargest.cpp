#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[]={1,2,3,2,4,1,3};
    int max=arr[0];
    int length=sizeof(arr)/sizeof(arr[0]);
   
    
    for(int i=0;i<length;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int sec_max=arr[0];
    for(int i=0;i<length;i++){
        if(arr[i]>sec_max&&arr[i]!=max){
            sec_max=arr[i];
        }
    }

    cout<<sec_max;


}
