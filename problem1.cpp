#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
    unordered_map<int, unordered_set<int>> movieBookings;

public:
    bool book(int user, int movie) {
        auto &users = movieBookings[movie];

        if (users.count(user)) return false;     // already booked
        if (users.size() == 100) return false;   // full

        users.insert(user);
        return true;
    }

    bool cancel(int user, int movie) {
        if (!movieBookings.count(movie)) return false;

        auto &users = movieBookings[movie];

        if (!users.count(user)) return false;

        users.erase(user);
        return true;
    }

    bool isBooked(int user, int movie) {
        if (!movieBookings.count(movie)) return false;
        return movieBookings[movie].count(user);
    }

    int availableTickets(int movie) {
        if (!movieBookings.count(movie)) return 100;
        return 100 - movieBookings[movie].size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    MovieTicket system;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.book(X, Y) ? "true" : "false") << '\n';
        }
        else if (op == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.cancel(X, Y) ? "true" : "false") << '\n';
        }
        else if (op == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.isBooked(X, Y) ? "true" : "false") << '\n';
        }
        else if (op == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << system.availableTickets(Y) << '\n';
        }
    }

    return 0;
}
