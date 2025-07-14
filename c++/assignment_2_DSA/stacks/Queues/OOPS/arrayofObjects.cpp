#include <iostream>
using namespace std;

class MyClass {
    private:
        int x, y;
    public:
        void set_data(int a, int b) {
            x = a;
            y = b;
        }

        void update_data(MyClass arr[], int size) {
            for(int i = 0; i < size; ++i) {
                arr[i].x += 1;
                arr[i].y += 1;
            }
        }

        void output() {
            cout << "x = " << x << ", y = " << y << endl;
        }
};

int main() {
    int size = 3; // Array size
    MyClass* arr = new MyClass[size];

    // Set data for each object in the array
    for(int i = 0; i < size; ++i) {
        int a, b;
        cout << "Enter values for object " << i+1 << ": ";
        cin >> a >> b;
        arr[i].set_data(a, b);
    }

    // Update data in the array
    arr[2].update_data(arr, size);

    // Output the updated data
    for(int i = 0; i < size; ++i) {
        arr[i].output();
    }

    // Clean up
    delete[] arr;
    return 0;
}
