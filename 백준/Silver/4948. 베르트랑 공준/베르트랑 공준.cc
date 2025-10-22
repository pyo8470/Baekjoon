#include <cstring>
#include <iostream>
using namespace std;
const int N = 123456;

int che[N * 2 + 1];

bool is_prime(int n) {
    if (n == 2)
        return true;
    if (n == 0 || n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void init() {
    memset(che, 0, sizeof(che));

    for (int i = 2; i <= 2 * N; i++) {
        if (is_prime(i)) {
            che[i] = che[i - 1] + 1;
        } else {
            che[i] = che[i - 1];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        int n_2 = 2 * n;
        int ans = 0;
        ans += (che[n_2] - che[n]);
        cout << ans << '\n';
    }
}