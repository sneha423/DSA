#include <iostream>
#include <limits.h> // For INT_MAX

using namespace std;

// Template for optimalBrack function to handle flexible array sizes
template <size_t N>
void optimalBrack(int (&s)[N][N], int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        optimalBrack(s, i, s[i][j]);
        optimalBrack(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int constructing_sol(int arr[], int n) {
    int m[n][n];
    int s[n][n];                                                                                                               
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = INT_MAX;
            s[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    for (int l = 2; l < n; l++) {
        for (int i = 1; i <= n - l; i++) {
            int j = i + l - 1;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                cout << "previous q: " << q << endl;
                if (m[i][j] > q) {
                    m[i][j] = q;
                    cout << q << endl;
                    s[i][j] = k;
                }
            }
        }
    }

    optimalBrack(s, 1, n - 1);
    return m[1][n - 1];
}

int main() {
    int p[] = {5, 4, 6, 2, 7};
    int n = sizeof(p) / sizeof(p[0]);
    cout << "n: " << n << endl;
    cout << "solution:  " << constructing_sol(p, n) << endl;
}
