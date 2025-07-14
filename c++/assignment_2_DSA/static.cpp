#include<iostream>
using namespace std;
class A{
int i;
public:  A(){i=10;}
void show(){cout<<"i = "<<i<<endl;}
A makedouble(A obj){A temp; temp.i = 2*obj.i; return temp;}
};
int main(){
A a1,a2;  a1.show();  a2 = a1.makedouble(a1);  a2.show();
}
