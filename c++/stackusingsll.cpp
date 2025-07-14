
// C++ program to implement a stack using singly linked list
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

// Class to implement stack using a singly linked list
class Stack {
    Node* head;

public:
    Stack() { this->head = NULL; }

    bool isEmpty() {

        if (this->head==NULL)
            return true;
        else
            return false;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* new_node = new Node(value);
        if (new_node==NULL) {
            cout << "\nStack Overflow";
        }

        // Link the new node to the current top node
        new_node->next = head;
        // Update the top to the new node
        head = new_node;
    }

    // Function to remove the top element from the stack
    void pop() {
        // Check for stack underflow
        if (isEmpty()) {
            cout << "\nStack Underflow" << endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to return the top element of the stack
    int peek() {

        // If stack is not empty, return the top element
        if (!isEmpty())
            return head->data;
        else {
            cout << "\nStack is empty";
            return -1;
        }
    }
};


int main() {
    Stack st;

    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    cout << "Top element is " << st.peek() << endl;

    return 0;
}