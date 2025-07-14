#include<iostream>
using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void optBubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                flag=false;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    
    if(flag==true){
        break;
    }
    }
    display(arr,n);

}
int main(){
    
    int arr[]={1,3,4,7,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    optBubbleSort(arr,n);
    return 0;
}