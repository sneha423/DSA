//find the unique no. in a given array where all the elements
//are being repeated twice with one value being unique

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={1,2,3,2,4,1,3};
    int length=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<length;i++){
        for(int j=i+1;j<length;j++){
            if(arr[i]==arr[j]){
                arr[i]=arr[j]=-1; 
            }
        }
    }
    for(int i=0;i<length;i++){
        if(arr[i]>0){
            cout<<arr[i]<<endl;
        }
    }
}