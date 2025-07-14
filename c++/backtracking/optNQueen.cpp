#include<iostream>
#include<vector>
#include<string>
using namespace std;

class solution {
public:
    void NQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans,
                vector<char> &leftdiog, vector<char> &rightdiog, vector<char> &colUsed) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (colUsed[j] == '-' && leftdiog[n - 1 + j - row] == '-' && rightdiog[row + j] == '-') {
                board[row][j] = 'Q';
                colUsed[j] = 'Q';
                leftdiog[n - 1 + j - row] = 'Q';
                rightdiog[row + j] = 'Q';

                NQueen(board, row + 1, n, ans, leftdiog, rightdiog, colUsed);

                board[row][j] = '-';
                colUsed[j] = '-';
                leftdiog[n - 1 + j - row] = '-';
                rightdiog[row + j] = '-';
            }
        }
    }

    vector<vector<string>> solveNQueen(int n) {
        vector<string> board(n, string(n, '-'));
        vector<vector<string>> ans;
        vector<char> leftdiog(2 * n - 1, '-');
        vector<char> rightdiog(2 * n - 1, '-');
        vector<char> colUsed(n, '-');

        NQueen(board, 0, n, ans, leftdiog, rightdiog, colUsed);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    solution s;
    vector<vector<string>> solutions = s.solveNQueen(n);

    cout << "\nSolutions:\n";
    for (const auto &sol : solutions) {
        cout << endl;

        for (const auto &row : sol) {
            cout << row << endl;
        }

        cout << "Positions of queens: ";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (sol[i][j] == 'Q') {
                    cout << j + 1;
                    if (i != n - 1) cout << ",";
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
