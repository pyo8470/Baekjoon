#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    cout << ((n - 1) * (n) * (2 * n - 1) / 6 - n * (n - 1) / 2) / 2 << "\n" << 3;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}