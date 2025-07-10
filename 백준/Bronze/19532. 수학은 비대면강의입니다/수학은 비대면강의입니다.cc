#include <bits/stdc++.h>
#include <climits>
using namespace std;
int main()
{
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // 브루트포스 말고

    // ax + by = c
    // dx + ey = f

    // a,d 계수 맞추기

    double denominator = a*e - b*d;

    int x = (c * e - b * f) / denominator;
    int y = (a * f - c * d) / denominator;
    printf("%d %d", x, y);
}
