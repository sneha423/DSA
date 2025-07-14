#include<iostream>
#define MAXLEN 100
using namespace std;


  class  stack{
int ele[MAXLEN];
int top;

 stack init(){
    stack S;
    
S.top=-1;
return S;
}
int isEmpty(stack S){
return(S.top==-1);
}
int isFull(stack S){
    return(S.top==MAXLEN-1);
}
    };
    






int main(){

}