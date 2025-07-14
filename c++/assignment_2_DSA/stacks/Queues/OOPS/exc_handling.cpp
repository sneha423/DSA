#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter a"<<endl;
    cin>>a;
    cout<<"enter b"<<endl;
    cin>>b;

    try{
        if(b==0){
            throw b;
        }
        else{
            cout<<"result : "<<(a/b)<<endl;
        }
    }

    catch(int x){
        cout<<"error"<<endl;
    }
    return 0;
}