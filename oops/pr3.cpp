#include<iostream>
#include<vector>
using namespace std;
template <typename T1, typename T2, int size = 10>
class MultiTypeContainer {
private: T1 first; T2 second; T1 array[size];
public:
void setFirst(T1 value) { first = value; }
void setSecond(T2 value) { second = value; }
void printDetails() { cout << "First: " << first << ", Second: " << second <<
", Array Size: " << size <<endl; }
};
int main(){
MultiTypeContainer<int, string> Container1;
MultiTypeContainer<double, char, 5> Container2;
Container1.setFirst(2);
Container1.setSecond("sneha");
Container1.printDetails();
Container2.printDetails();
 }