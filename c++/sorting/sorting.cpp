#include<iostream>
using namespace std;

// void selSort(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[j]<arr[i]){
//                 int temp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=temp;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }

void bubble_sort(int arr[],int n){
    bool flag;

        for(int i=0;i<n-1;i++){
            flag=true;

            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    flag=false;
                    int temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=arr[j+1];

                }
            }
            if(flag==true) return;
        }
     
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current&& j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // selSort(arr,n);
    // cout<<endl;
    bubble_sort(arr,n);
    insertionSort(arr,n);
    return 0;
}