#include<iostream>
using namespace std;
// Template class example
// template <class T>
// class Test {
// T var;
// public:
// Test (T i) {var=i;}
// T divideBy2 () {return var/2;}
// };
// int main(){
// Test <int> t1(50);
// Test <double> t2(-10.20);
// cout<<t1.divideBy2()<<" "<<t2.divideBy2()<<endl;
// }

template <class T, int n>
class Test {
T var;
public:
Test () {var = n; cout<<"n = "<<n<<endl;}
T divideBy2 () {return var/2;}
};
int main(){
Test <int,10> t1;
Test <double,20> t2;
cout<<t1.divideBy2()<<" "<<t2.divideBy2()<<endl;
}