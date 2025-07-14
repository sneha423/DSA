#include<iostream>
using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int deleteDuplicateElements(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        int j;
        for( j=i+1;j<=n;j++){
            if(arr[i]==arr[j]){
                for(int k=j;k<n;k++){
                    arr[k]=arr[k+1];
                }
                 n--;
                j--;
            }
        }
    }
     return n;
}
int main(){
    int arr[]={1,4,2,5,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    int new_n=deleteDuplicateElements(arr,n);
    display(arr,new_n);
   
    return 0;
}