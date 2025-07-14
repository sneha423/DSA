#include<iostream>
using namespace std;
#define n 3
class queue{
    int* arr;
    int front;
    int back;
public:
queue(){
    arr=new int[n];
    front=back=-1;
}
bool isFull(){
    if(back==n-1){
        return true;
    }
    return false;
}
bool isEmpty(){
    if(front==-1||front>back){
        return true;
    }
    return false;
}
void push(int x){
    if(isFull()){
        cout<<"queue is full"<<endl;
    }
    if(front==-1&&back==-1){
        back=front=1;
        arr[back]=x;
    }
    else{
        back++;
        arr[back]=x;
    }
}
void pop(){
    if(isEmpty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        front++;
    }
}
void peek(){
    if(isEmpty()){
        cout<<"no elements"<<endl;
    }
    cout<<arr[front]<<endl;;
}
};

int main(){
    queue q;
    q.pop();
    q.push(9);
    q.push(2);
    q.peek();
    q.pop();
    q.push(5);
    q.peek();
    q.push(6);
    q.pop();
    return 0;
}