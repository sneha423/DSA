#include<iostream>
#include<queue>
using namespace std;
void push_stack(int x){
    int l=q1.size();
if(q1.empty()){
q1.push(x);
}
else{
    for(int i=0;i<l-1;i++){
        q2.push(q1.pop());
    }
    q1.push(x);
}
for(int j=0;j<l-1;j++){
    q1.push(q2.pop());
}
}
int pop_stack(){
int item = q1.pop();
return item;
}
int main(){
    queue<int> q1,q2;
    q1.push_stack(1);
    q1.push_stack(5);
    q1.push_stack(3);
    q1.pop_stack();
    q1.push_stack(2);
    q1.pop_stack();

    return 0;
}