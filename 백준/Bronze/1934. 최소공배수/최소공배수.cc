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

    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        if (A < B)
            swap(A, B);
        int gcd = GCD(A, B); // 최대 공약수
        int lcm = A * B / gcd; // 최소 공배수

        cout << lcm << '\n';
    }
}