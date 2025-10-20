#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    cout << (n) * (n - 1) / 2 << "\n" << 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}