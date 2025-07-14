#include<iostream>
using namespace std;



int main(){
int arr[]={1,4,3,7,6,9};
int l= sizeof(arr)/sizeof(arr[0]);
int count=0;
int i,j;
for(int i=0;i<l;i++){
    for(int j=i+1;j<l;j++){
    if(arr[i]>arr[j]){
        count++;
    }
     }
}
cout<<count;
}