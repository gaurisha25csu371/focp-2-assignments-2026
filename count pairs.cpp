#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

int spf[MAXN + 1];

void sieve() {
    for (int i = 1; i <= MAXN; i++) spf[i] = i;

    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int countDistinctPrimes(int n) {
    int count = 0;
    while (n > 1) {
        int prime = spf[n];
        count++;
        while (n % prime == 0)
            n /= prime;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int k = countDistinctPrimes(n);
        cout << (1 << k) << '\n';
    }

    return 0;
}
