#include<iostream>
#include<algorithm>   //header file for using sort
using namespace std;
int main(){
    //for array
    sort(a,a+n);  //(first pos, rightt after last pos)
    //for vectors
    sort(v.begin(),v.end());
    //for descending order in array
    sort(a,a+n,greater<int>);

    //if you have to make a myway order
    sort(a,a+n,comp) //comp is the self written comparator
                     //it is a boolean function

}


