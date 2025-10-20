#include <iostream>
#include <string>
#include <vector>
using namespace std;

void init() {}

bool is_doomsday(int n) {
    string s = to_string(n);
    if (s.find("666") != string::npos) {
        return true;
    }
    return false;
}

void solve() {
    int N;
    cin >> N;
    int count = 0;
    int number = 665;

    while (true) {
        number++;
        if (is_doomsday(number))
            count++;

        if (count == N) {
            cout << number << '\n';
            break;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}