//sweep line algorithm
#include<iostream>
#include<algorithm>
using namespace std;
int countPlatforms(int arr1[],int arr2[],int n){
    int count=0;
    int plat_needed=0;
    int m=arr2[0];
    for(int i=0;i<n;i++){
        if(arr2[i+1]>arr2[i]){
            m=arr2[i+1];
        }
    }
    int final_arr[m+2]={0};
    for(int i=0;i<n;i++){
        final_arr[arr1[i]]++;
        final_arr[arr2[i]+1]--;
    }
    for(int i=0;i<m+2;i++){
        count+=final_arr[i];
        plat_needed=max(plat_needed,count);
    }
    return plat_needed;
}
int main(){
    int arr_time[]={900,940,950,1100,1500,1800};
    int dept_time[]={910,1200,1120,1130,2000,1900};
    int n=sizeof(dept_time)/sizeof(dept_time[0]);
    cout<<"platforms:"<<countPlatforms(arr_time,dept_time,n);
    return 0;
}