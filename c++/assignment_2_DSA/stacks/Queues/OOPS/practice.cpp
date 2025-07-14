#include<iostream>
using namespace std;
// class test
// {
// const int i;
// public:
// test():i(20)
// {
// }
// void setvalue(int x)
// {
// i=x;
// }
// void show()
// {

// cout<<i<<endl;

// }

// };
// int main()
// {
// test t1;
// t1.setvalue(10);
// t1.show();
// }
// class A{
// int i,j;
// public:
// A(int a=-99, int b=-88){ i=a; j=b;}
// void show(){cout<<"i="<<i<<" j = "<<j<<endl;}
// };
// int main(){
// A a, b(22),c(1,2);
// a.show(); b.show(); c.show();
// return 0;
// }

void swap(int,int);
int main()
{
int a=10,b=20;
cout<<"before function calling"<<a<<b;
swap(a,b);
cout<<"after function calling"<<a<<b;
return 0;
}
void swap(int x,int y)
{
int z;
z=x;
x=y;
y=z;
cout<<"value is"<<x<<y;
}
