#include <cstring>
#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n == 0 || n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 모든 수의 최대 공약수를 구한다.
    bool che[1000001];
    memset(che, 1, sizeof(che));

    int M, N;
    cin >> M >> N;

    che[1] = 0;
    che[0] = 0;

    for (int i = 2; i < 1000001; i++) {
        if (!che[i])
            continue;
        if (is_prime(i)) {
            int mul = 2;
            while (mul * i < 1000001) {
                che[mul * i] = false;
                mul++;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (che[i])
            cout << i << '\n';
    }
}