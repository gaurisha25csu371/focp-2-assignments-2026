#include <bits/stdc++.h>
using namespace std;

bool canTurnOff(string &bulbs, int n, int k, int x) {
    int ops = 0;

    for (int i = 0; i < n; i++) {
        if (bulbs[i] == '1') {
            ops++;
            i += x - 1; // skip next x-1 bulbs
        }
        if (ops > k) return false;
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;

    int left = 1, right = n, ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, n, k, mid)) {
            ans = mid;
            right = mid - 1; // try smaller x
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
