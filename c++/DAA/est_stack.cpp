// #include<iostream>
// using namespace std;
// #define MAXLEN 100

// class stack{
//     int element[5];
//     int top=-1;

// public:
//     int isFull()
//     {
//         if (top==4) //MAXLEN-1
//             return 1;
//                 //wait for else
//         else
//           return 0;

//           //return (top==4)
//     }
//     void push(int x)
//     {
//         if(isFull())
//             cout<<"\n Overflow";
//         else
//             top++;
//             element[top]= x;
//     }
//     void display()
//     {
//         for (int i=top;i>=0;i--)
//             cout<<element[i]<<endl;
//     }
//     int isEmpty()
//     {
//         if(top==-1)
//             return 1;
//         else
//             return 0;
//     }
//     void topp() //peek()
//     {
//         if(isEmpty())
//         {
//             cout<<"Underflow";
//         }
//         else
//             cout<<element[top];
//     }
//     void pop()
//     {
//         if(isEmpty())
//         {
//             cout<<"Underflow";
//         }
//         else
//             top--;
//     }


// };


// int main()
// {
//     stack S;
//     for (int i=0;i<=4;i++)
//         S.push(10+i);
//     S.display();
//     S.push(50);
//     //S.display();
//     cout<<"Top element is ";
//     S.topp();
// }

#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) {
            cout << "Stack is empty. Cannot perform pop operation." << endl;
            return;
        }
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty. No minimum element." << endl;
            return -1; // Indicating stack is empty
        }
        return minStack.top();
    }

    void printStacks() {
        stack<int> tempMain = mainStack;
        stack<int> tempMin = minStack;

        cout << "Main Stack: ";
        while (!tempMain.empty()) {
            cout << tempMain.top() << " ";
            tempMain.pop();
        }
        cout << endl;

        cout << "Min Stack: ";
        while (!tempMin.empty()) {
            cout << tempMin.top() << " ";
            tempMin.pop();
        }
        cout << endl;
    }
};

int main() {
    SpecialStack specialStack;

    specialStack.push(10);
    specialStack.printStacks();
    cout << "Current Min: " << specialStack.getMin() << endl; // Should return 10

    specialStack.push(5);
    specialStack.printStacks();
    cout << "Current Min: " << specialStack.getMin() << endl; // Should return 5

    specialStack.push(2);
    specialStack.printStacks();
    cout << "Current Min: " << specialStack.getMin() << endl; // Should return 2

    specialStack.pop();
    specialStack.printStacks();
    cout << "Current Min: " << specialStack.getMin() << endl; // Should return 5

    return 0;
}
