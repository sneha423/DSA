#include <iostream>
#define MAXLEN 4

using namespace std;

class Queue {
   private:
  int items[MAXLEN], front, rear;

   public:
  Queue() {
    front = -1;
    rear = -1;
  }
  // Check if the queue is full
  bool isFull() {
    if (front == 0 && rear == MAXLEN - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
  }
  // Check if the queue is empty
  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }

  // Adding an element
  void enqueue(int element) {
        if (isFull())
            cout << "\nQUEUE IS FULL\n";
        else {
          if (front == -1)
            front = 0;
          rear = (rear + 1) % MAXLEN;
          items[rear] = element;
          //cout<<"\nITEM INSERTED: "<<element <<" at index "<<rear<<endl;
    }
  }
  // Removing an element
  int dequeue() {
    int element;
    if (isEmpty())
      cout << "\nQUEUE IS EMPTY\n" << endl;
    else {
       element = items[front];
       if (front == rear) {
            front = -1;
            rear = -1;
      }

      else
        front = (front + 1) % MAXLEN;
      return (element);
    }
  }

  void display() {
    int i;
    if (isEmpty())
        cout << "\nQUEUE IS EMPTY\n" << endl;
    else {
      cout << endl<< "Items = ";
      for (i = front; i != rear; i = (i + 1) % MAXLEN)
        cout << items[i]<<" ";
      cout <<items[i];
    }
  }

    // void size()
    // {
    //     //int s= rear-front+1;
    //     //cout<<"\nSize is ="<<s;
    //     int s;
    //     if(rear>=front)
    //         s=rear-front+1;
    //     else
    //         s= MAXLEN-(front-rear-1);
    //     cout<<"Number of elements in queue :"<<s;
    // }

    // void sortQ(){
    //     int minidx=front;
    //     int minval;
    //     for(int i=front;i!=rear;i=(i+1)%MAXLEN){
    //         if(items[front]>items[(front+1)%MAXLEN]){
    //             minidx=(front+1)%MAXLEN;
    //         }
    //         minval=items[minidx];
    //     }

    //     for(int i=front;i<=minidx-1;i=(i+1)%MAXLEN){
    //         enqueue(dequeue());
    //     }

    //     int a=items[minidx];

    //     for(int i=minidx+1;i!=rear;i=(i+1)%MAXLEN){
    //         enqueue(dequeue());
    //     }

    //     enqueue(a);
    // }

    void sortQ() {
    int minidx = front;
    int minval = items[front];

    // Find the minimum element and its index
    for (int i = (front + 1) % MAXLEN; i != rear; i = (i + 1) % MAXLEN) {
        if (items[i] < minval) {
            minidx = i;
            minval = items[i];
        }
    }

    // Move elements before minidx to the end of the queue
    for (int i = front; i != minidx; i = (i + 1) % MAXLEN) {
        enqueue(dequeue());
    }

    // Dequeue the minimum element
    int a = dequeue();

    // Move remaining elements back to the queue
    for (int i = (minidx + 1) % MAXLEN; i != rear; i = (i + 1) % MAXLEN) {
        enqueue(dequeue());
    }

    // Enqueue the minimum element to the front
    enqueue(a);
}

};
int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(2);
    q.display();
    q.sortQ();
    q.display();
}
