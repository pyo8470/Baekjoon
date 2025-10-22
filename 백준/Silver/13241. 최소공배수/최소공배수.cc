#include <iostream>
#include <utility>

using namespace std;

int GCD(int A, int B) {
    if (B == 0)
        return A;
    return GCD(B, A % B);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long A, B;
    cin >> A >> B;

    if (A < B)
        swap(A, B);
    long long gcd = GCD(A, B);
    long long lcm = A * B / gcd;
    cout << lcm;
}