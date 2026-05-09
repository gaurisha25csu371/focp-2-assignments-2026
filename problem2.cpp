#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<int, long long> accounts;

public:
    bool create(int user, long long amount) {
        if (!accounts.count(user)) {
            accounts[user] = amount;
            return true;
        } else {
            accounts[user] += amount;
            return false;
        }
    }

    bool debit(int user, long long amount) {
        if (!accounts.count(user)) return false;
        if (accounts[user] < amount) return false;

        accounts[user] -= amount;
        return true;
    }

    bool credit(int user, long long amount) {
        if (!accounts.count(user)) return false;

        accounts[user] += amount;
        return true;
    }

    long long balance(int user) {
        if (!accounts.count(user)) return -1;
        return accounts[user];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "CREATE") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << '\n';
        }
        else if (op == "DEBIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << '\n';
        }
        else if (op == "CREDIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << '\n';
        }
        else if (op == "BALANCE") {
            int X;
            cin >> X;
            cout << bank.balance(X) << '\n';
        }
    }

    return 0;
}
