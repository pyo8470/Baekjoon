#include <iostream>
#include <numeric>
#include <utility>

using namespace std;

int GCD(const int& A, const int& B) {
    if (B == 0)
        return A;
    return gcd(B, A % B);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a1, a2;
    int b1, b2;

    cin >> a1 >> b1 >> a2 >> b2;

    // 분모 = 최소 공배수
    // 분자 ->( 최소 공배수 / 각 분모 ) * 분자

    int t_b1 = b1, t_b2 = b2;
    int gcd = GCD(t_b1, t_b2);
    int lcm = b1 * b2 / gcd;  // 최소 공배수;

    a1 = lcm / b1 * a1;
    a2 = lcm / b2 * a2;

    int up = a1 + a2;
    int down = lcm;

    int t_up = up;
    int t_down = down;
    if (up < down)
        swap(up, down);

    int div_gcd = GCD(up, down);

    cout << t_up / div_gcd << " " << t_down / div_gcd;
}