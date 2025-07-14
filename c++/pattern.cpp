#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<(n+1)/2;i++){
        for(int k=0;k<((n+1)/2)-1;k++){
            cout<<" ";
        }
        cout<<"*";
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        cout<<"*";
    }
    cout<<"\n";
    for(int i=1;i<(n+1)/2;i++){
        for(int k=0;k<((n+1)/2)-1;k++){
            cout<<" ";
        }
        cout<<"*";
        cout<<"\n";
    }
    return 0;
}