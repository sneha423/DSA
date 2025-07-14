#include<iostream>
using namespace std;
class test{
int a,b;
public:
void getdata(int x,int y){
    a=x;
    b=y;
}
void show(){
    cout<<a<<endl;
    cout<<b<<endl;
}
//unary minus
// void operator -(){
//     a=-a;
//     b=-b;
// }

// logical not
// void operator !(){
//     a=!a;
//     b=!b;
// }
};
int main(){
    test t;
    t.getdata(0,1);
    t.show();
    t.operator -();
    t.show();
    t.operator!();
    t.show();
}