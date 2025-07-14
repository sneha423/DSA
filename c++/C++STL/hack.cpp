#include <bits/stdc++.h>
#include <numeric>

using namespace std;

typedef long long ll;
const int MOD = 531169;
const int MAX = 200005;

ll fact[MAX], invFact[MAX], mobius[MAX];

// Fast exponentiation
ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precomputeFactorials() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invFact[i] = power(fact[i], MOD - 2); // Fermat's inverse
    }
}

// Compute nCr modulo MOD
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// Precompute Mobius function up to MAX
void computeMobius() {
    for (int i = 1; i < MAX; i++) mobius[i] = 1;
    vector<bool> isPrime(MAX, true);

    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = i; j < MAX; j += i) {
                mobius[j] *= -1;
                isPrime[j] = false;
            }
            for (ll j = 1LL * i * i; j < MAX; j += i * i) {
                mobius[j] = 0;
            }
        }
    }
}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


// Main logic to count unbreakable sequences
ll unbreakableSequences(int A, int B) {
    int total = A + B;
    int g = gcd(A, B);
    ll ans = 0;

    for (int d = 1; d <= g; ++d) {
        if (g % d != 0) continue;
        int a = A / d;
        int b = B / d;
        ll term = nCr(a + b, a);
        ans = (ans + mobius[d] * term % MOD + MOD) % MOD;
    }
    return ans;
}

int main() {
    precomputeFactorials();
    computeMobius();

    int A, B;
    cin >> A >> B;

    cout << unbreakableSequences(A, B) << endl;

    return 0;
}
