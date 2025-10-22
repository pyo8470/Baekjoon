#include <cstring>
#include <iostream>

using namespace std;

const int MAX = 1000001;
bool che[MAX];

inline bool is_prime(const int& n) {
    if (n == 2)
        return true;
    if (n % 2 == 0 || n == 0 || n == 1)
        return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void init() {
    memset(che, true, sizeof(che));
    che[0] = che[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (is_prime(i)) {
            int mul = 2;
            while (mul * i < MAX) {
                che[mul * i] = false;
                mul++;
            }
        }
    }
}

int solve(int n) {
    int l = 2, r = n - 2;
    int cnt = 0;
    while (l <= r) {
        if (!che[l] || !che[r]) {
            if (!che[l])
                l++;
            if (!che[r])
                r--;
            continue;
        }

        if (l + r == n) {
            cnt++;
            l++;
            r--;
        } else if (l + r > n) {
            r--;
        } else {
            l++;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    init();
    while (T--) {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}