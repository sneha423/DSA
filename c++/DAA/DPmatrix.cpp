#include <iostream>
#include <climits>
using namespace std;

// Recursive function to print optimal brackets
template<int N>
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
    int m[100][100];  // Using fixed size array (you can make this dynamic with vector if needed)
    int s[100][100];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) {  // l is chain length
        for (int i = 1; i <= n - l; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Optimal Parenthesization: ";
    optimalBrack(s, 1, n - 1);
    cout << endl;
    return m[1][n - 1];
}

int main() {
    int p[] = {5, 4, 6, 2, 7};
    int n = sizeof(p) / sizeof(p[0]);
    cout << "Number of matrices: " << n - 1 << endl;
    int cost = constructing_sol(p, n);
    cout << "Minimum number of multiplications: " << cost << endl;
    return 0;
}
