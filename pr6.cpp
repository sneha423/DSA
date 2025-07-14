#include<iostream>
using namespace std;
class Base{
public:
Base(){cout<<"Base Constructure";}
virtual ~Base(){cout<<"Base Destructure";}
};
class Derived: public Base{
public:
Derived(){cout<<"Derived Constructure";}
~Derived(){cout<<"Derived Destructure";}
};
int main(void){
Base *obj=new Derived();
 delete obj;
return 0;
}