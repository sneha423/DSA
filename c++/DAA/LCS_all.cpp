#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to build the LCS length table
vector<vector<int>> lcsLength(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
        }
    }

    return c;
}

// Recursive function to collect all LCS
set<string> allLCS(string X, string Y, int i, int j, vector<vector<int>>& c) {
    if (i == 0 || j == 0)
        return {""};

    if (X[i - 1] == Y[j - 1]) {
        set<string> lcs = allLCS(X, Y, i - 1, j - 1, c);
        set<string> result;
        for (const string& s : lcs) {
            result.insert(s + X[i - 1]);
        }
        return result;
    }

    set<string> result;
    if (c[i - 1][j] >= c[i][j - 1])
        result = allLCS(X, Y, i - 1, j, c);

    if (c[i][j - 1] >= c[i - 1][j]) {
        set<string> temp = allLCS(X, Y, i, j - 1, c);
        result.insert(temp.begin(), temp.end());
    }

    return result;
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";

    vector<vector<int>> c = lcsLength(X, Y);

    set<string> result = allLCS(X, Y, X.length(), Y.length(), c);

    cout << "All Longest Common Subsequences:\n";
    for (const string& lcs : result)
        cout << lcs << endl;

    return 0;
}
