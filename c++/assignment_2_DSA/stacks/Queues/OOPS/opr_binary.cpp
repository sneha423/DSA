#include<iostream>
using namespace std;
class test{
    int a,b;
    public:
    void getdata(int x){
        a=x;
        // b=y;
    }
    void show(){
        cout<<a<<endl;
        // cout<<b<<endl;
    }
    // test operator +(test y){
    //     test h;
    //     h.a=a+y.a;
    //     h.b=b+y.b;
    //     return h;

    // }

    // bool operator <(test y){
    //     if(a<y.a){
    //         return 1;
    //     }
    //     else{
    //         return 0;
    //     }
    // }

    test operator &&(test y){
        test h;
        h.a=a&&y.a;
        return h;
    }

    test operator ||(test y){
        test h;
        h.a=a||y.a;
        return h;
    }
};
int main(){
    test t1,t2,t3,t4;
    // t1.getdata(45,34);
    // t2.getdata(12,32);
    // t3=t1.operator+(t2);
    // t3.show();

    // cout<<t1.operator<(t2);
    // if(t1<t2){
    //     cout<<"t1 is less"<<endl;
    // }
    // else{
    //     cout<<"t2 is less"<<endl;
    // }

    t1.getdata(0);
    t2.getdata(1);
    t3=t1.operator&&(t2);
    t3.show();
    t4=t1.operator||(t2);
    t4.show();
    return 0;
}