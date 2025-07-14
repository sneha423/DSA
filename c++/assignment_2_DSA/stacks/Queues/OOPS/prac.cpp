#include<iostream>
using namespace std;
 class base {
 public:
  
 void show()
 {    
cout << "base\n"; }
};
  class derived : public base {
 public:
 void show()
 {   
cout << "derived\n"; 
 }
 };
  int main()
  {    base b1;

 b1.show(); // base
 
 derived d1;
 d1.show(); // derived
 base *pb = &b1;
 pb->show(); // base
 pb = &d1;
 pb->show(); // base
  }