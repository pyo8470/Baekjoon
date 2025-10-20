#include <iostream>
#include <string>
#include <vector>
using namespace std;

void init() {}

void solve() {
    int N;
    cin >> N;

    for (int x = 0; x <= 2000; x++) {
        for (int y = 0; y <= 2000; y++) {
            if (3 * x + 5 * y == N) {
                cout << x + y;
                return;
            }
        }
    }
    cout << -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}