#include<iostream>
using namespace std;
 class test
 {
 public:
 const int x;
 test():x(20)
 {

 }
void show() const
{
cout<<x<<endl;
 }
};
int main()
 {
 const test t1;
 t1.show();
 }