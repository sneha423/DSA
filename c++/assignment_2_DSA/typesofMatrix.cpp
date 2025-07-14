#include<iostream>
using namespace std;
// int main(){
//     int arr[]={1,2,3,4};
//     int l=sizeof(arr)/sizeof(arr[0]);
//     int arr2[l][l];
//     for(int i=0;i<l;i++){
//         for(int j=0;j<l;j++){
//             if(i==j){
//                 cout<<" "<<arr[i]<<" ";
//             }
//             else{
//                 cout<<" 0 ";
//             }
            
//         }
//         cout<<endl;
//     }
// }

int main(){
    // int arr[k]={1,5,6,7,2,8,9,3,10,4};
    
    int l=4;
    int k=l*(l+1)/2;
       int arr[k]={1,5,6,7,2,8,9,3,10,4};
    int arr2[l][l];
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(i>=j){
                arr2[i][j]=arr[(j+1)*(j)/2];
                
              
            }
            else{
                arr2[i][j]=0;
            }
        }

    }
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            cout<<" "<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
}