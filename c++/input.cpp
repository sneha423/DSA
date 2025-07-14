#include<iostream>
using namespace std;

int main(){
    int a,b;
    float c= 3.14;
    cout<<(int(c));
    cout<<"enter a: ";
    cin>>a;
    cout<<"enter b: ";
    cin>>b;
    cout<<"the sum is: "<<a+b<<endl;
    
    cout<<(a==b)<<endl;
    cout<<(a!=b)<<endl;
    cout<<(a>>1)<<endl;
    cout<<(a<<1)<<endl;
    cout<<sizeof(a)<<endl;
    if(a==b){
        cout<<"no.'s are equal";
    }
    else{
        cout<<"no.'s are not equal";
    }
        return 0;
}