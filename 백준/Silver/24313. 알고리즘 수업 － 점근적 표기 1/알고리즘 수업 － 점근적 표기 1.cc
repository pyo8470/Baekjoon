#include <iostream>

using namespace std;

void solve() {
    int a_1, a_0, c, n_0;
    cin >> a_1 >> a_0 >> c >> n_0;

    if (a_1 > c) {
        cout << 0;
        return;
    }
    // 선형 함수 -> N값이 커질 수 록 차이가 날 것이다.
    // 따라서 첫 n_0값만 체크하면 된다.
    long long f_n = (long long)a_1 * n_0 + a_0;
    long long g_n = (long long)c * n_0;

    if (f_n <= g_n) {
        cout << 1;
    } else {
        cout << 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}