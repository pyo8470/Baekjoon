#include <iostream>
#include <vector>
using namespace std;

int N;
void init() { cin >> N; }
int getSum(int n) {
    int ret = n;
    while (n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
void solve() {
    for (int i = 1; i <= N; i++) {
        int k = getSum(i);
        if (k == N) {
            cout << i;
            return;
        }
    }
    cout << 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}