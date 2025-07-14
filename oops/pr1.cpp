#include <iostream>
#include <vector>
#include <algorithm> // For std::max
using namespace std;
// Template for finding the maximum of two values
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Template for finding the maximum value in an array
template <typename T>
T max(std::vector<T> arr) {
    T maxVal = arr[0];
    for (const auto& val : arr) {
        if (val > maxVal) {
            maxVal = val;
        }
    }
    return maxVal;
}

// Template for finding the maximum of three values
template <typename T>
T max(T a, T b, T c) {
    return max({a, b, c});
}

int main() {
    // Using the first template
    int a = 5, b = 10;
    cout << "Max of a and b: " << max(a, b) << endl;

    // Using the second template
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Max of array: " << max(arr) << endl;

    // Using the third template
    int x = 7, y = 2, z = 9;
    cout << "Max of x, y, and z: " << max(x, y, z) << \endl;

    return 0;
}
