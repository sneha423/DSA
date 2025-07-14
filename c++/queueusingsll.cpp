
//Simple Queue using Linked List
#include<iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
};
class Queue
{
 private:
  Node *front;
  Node *rear;

 public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enqueue (int data)
    {

      Node *newNode = new Node();
      newNode->data = data;
      newNode->next = nullptr;
        if( front == NULL )
         {
          front = newNode;
          rear = newNode;
         }
         else
         {
          rear ->next = newNode;
          rear = newNode;
         }
    }

    void dequeue ()
    {
       Node *temp = front;
      if (front == nullptr)
        {
          cout << ("Linked List Empty, nothing to delete");
          return;
        }

      else
        {
          front = temp->next;
        }
      cout<< "Deleted element: "<<temp->data<<endl;
      delete (temp);
    }

    void display ()
    {

      Node *temp = front;
      if (front == NULL)
        {
          cout << ("Linked List Empty, nothing to delete");
          return;
        }
      while (temp != NULL)
      {
          cout << temp->data << " ";
          temp = temp->next;
      }
      cout << endl;
    }
};
int main ()
{
  Queue q;
  q.enqueue (10);
  q.enqueue (20);
  q.enqueue (30);
  q.enqueue (40);
  //q.display ();

  q.dequeue ();
  q.dequeue ();
  q.display ();

  q.enqueue (50);
  q.enqueue (60);
  q.display ();

  return 0;
}