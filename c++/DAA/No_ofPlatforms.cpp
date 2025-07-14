// greedy algorithm
// this approach does not which train will go to which platform
// only tell the count of platforms required
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int countPlatforms(int arr1[],int arr2[],int n){
    vector<pair<int,int>> designation; 
    int plat_needed=1;
    int result=1;

    int i=1,j=0;
    designation.push_back(make_pair(plat_needed,1));
    while(i<n&&j<n){
        if(arr1[i]<=arr2[j]){
            plat_needed++;
            designation.push_back(make_pair(plat_needed,i+1));
            i++;
        }
        else if(arr1[i]>arr2[j]){
            plat_needed--;
            j++;
        }
        if(plat_needed>result){
            result=plat_needed;
        }
    }
    for(auto&pair:designation){
        cout<<"("<<pair.first<<" "<<pair.second<<")"<<endl;
        }
return result;
}
int main(){
    int arr_time[]={900,940,950,1100,1500,1800};
    int dept_time[]={910,1200,1120,1130,2000,1900};
    int n=sizeof(arr_time)/sizeof(arr_time[0]);
    sort(arr_time, arr_time + n);
    for(int i=0;i<n;i++){
        cout<<arr_time[i]<<" ";
    }
    cout<<endl;
    sort(dept_time, dept_time + n);
    for(int i=0;i<n;i++){
        cout<<dept_time[i]<<" ";
    }
    cout<<endl;
    cout<<countPlatforms(arr_time,dept_time,n);
    return 0;
}