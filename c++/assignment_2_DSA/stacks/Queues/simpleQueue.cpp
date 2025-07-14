#include<iostream>
#define MAXLEN 5
using namespace std;

class Queue{
    int front,rear;
    int queue[5];
    public:
    Queue(){
        front=rear=-1;
    }
    bool isEmpty(){
        if(front==-1||front>rear){
            return true;
        }
            else{
                return false;
            }
        }

    bool isFull(){
        if(rear==MAXLEN-1){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"overflow";
        }
        else if(front==-1&&rear==-1){
            front=rear=0;
            queue[rear]=x;
            cout<<x<<" inserted at "<<rear<<endl;
        }
        else{
            rear++;
            queue[rear]=x;
            cout<<x<<" inserted at "<<rear<<endl;
        }
    }
    void dequeue(){
        int x;
        if(isEmpty()){
            cout<<"underflow";
        }
        else if(front==0&&rear==0){
            x=queue[front];
            cout<<x<<" deleted from "<<front<<endl;
            front=rear=-1;
            
        }
        else{
            x=queue[front];
            cout<<x<<" deleted from "<<front<<endl;
            front++;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"queue is empty";
        }
        else{
            for(int i=front;i<=rear;i++){
                cout<<queue[i]<<endl;
            }
        }
    }
};      

    


int main(){
    Queue q1;
    q1.display();
    q1.enqueue(3);
    q1.enqueue(5);
    q1.enqueue(0);
    q1.dequeue();
    q1.display();

}