//sort an array consisting of zeroes and ones

#include<iostream>
#include<vector>
using namespace std;

    // int arr[]={1,1,0,0,1,0,1,0};
    // int l=sizeof(arr)/sizeof(arr[0]);
    // int zcount=0;
    // int ocount=0;
    // int new_arr[l];
    // for(int i=0;i<l;i++){
    //     cout<<arr[i]<<",";
    // }
    // cout<<endl;
    // for(int i=0;i<l;i++){
    //     if(arr[i]==0){
    //         zcount++;
    //     }
    //     else{
    //         ocount++;
    //     }
    // }
    // for(int i=0;i<zcount;i++){
    //     cout<<"0"<<",";
    // }
    // for(int i=0;i<ocount;i++){
    //     cout<<"1"<<",";
    // }
    // cout<<endl;

//     void sortZeroesAndOnes(vector<int> &v){
//         int zcount=0;
//         for(int ele:v){
//             if(ele==0){
//                 zcount++;
//             }
//         }
//         for(int i=0;i<v.size();i++){
//             if(i<zcount){
//                 v[i]=0;
//             }
//             else{
//                 v[i]=1;
//             }
//         }
       
//     }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v;
//     for(int i=0;i<n;i++){
//         int ele;
//         cin>>v[ele];
//         v.push_back(v[ele]);
//     }
//     sortZeroesAndOnes(v);

//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<",";
//     }
//     cout<<endl;
//     return 0;
// }
void sortZeroesAndOnes(vector<int> &v){
    int left_ptr=0;
    int right_ptr=v.size()-1;
    

    while(left_ptr<right_ptr){
        if(v[left_ptr]%2==1&&v[right_ptr]%2==0){
            // v[left_ptr]=0;
            // v[right_ptr]=1;
            swap(v[left_ptr],v[right_ptr]);
            left_ptr++;
            right_ptr--;
        }
        if(v[left_ptr]%2==0){
            left_ptr++;
        }
        if(v[right_ptr]%2==1){
            right_ptr--;
        }
        return;
    }
}
int main(){
    
vector<int> v={1,6,2,5,0,9,0};
    // for(int i=0;i<n;i++){
    //     int ele;
    //     cin>>v[ele];
    //     v.push_back(v[ele]);
    // }
    sortZeroesAndOnes(v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<",";
    }
    cout<<endl;
    return 0;
}