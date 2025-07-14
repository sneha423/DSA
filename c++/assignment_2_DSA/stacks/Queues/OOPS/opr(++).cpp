#include<iostream>
using namespace std;
class test{
int a;
public:
void getdata(int x){
    a=x;
}
void show(){
    cout<<a<<endl;
}
//pre-increment
// test operator ++(){
//     test h;
//     h.a=++a;
//     return h;
// }

//post-increment
test operator ++(int){
    test h;
    h.a=a++;
    return h;
}
};
int main(){
    test t1;
    t1.getdata(3);
    t1.show();
    // t1.operator++();
    // t1.show();
    t1.operator ++(5);
    t1.show();
}