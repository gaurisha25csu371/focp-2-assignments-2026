#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int>& a) {
    // Step 1: remove duplicates
    set<int> s(a.begin(), a.end());

    // Step 2: put into vector and sort descending
    vector<int> v(s.begin(), s.end());
    sort(v.rbegin(), v.rend());

    long long alex = 0, bob = 0;

    // Step 3: alternate picking
    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0)
            alex += v[i];
        else
            bob += v[i];
    }

    // Step 4: decide winner
    if (alex > bob)
        return "Alex";
    else
        return "Bob";
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << solve(n, a);

    return 0;
}
