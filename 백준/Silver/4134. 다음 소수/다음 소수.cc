#include <iostream>
using namespace std;

bool is_prime(long long num) {
    if (num == 0 || num == 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (long long i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

long long solve(long long n) {
    while (!is_prime(n)) {
        n++;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 모든 수의 최대 공약수를 구한다.
    long long T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}