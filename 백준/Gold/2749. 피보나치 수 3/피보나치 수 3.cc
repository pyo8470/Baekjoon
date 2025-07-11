#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{

    const int MOD = 1000000;
    const int PISANO = 1500000; // 피사노 주기

    long long n;
    cin >> n;

    vector<int> dp(PISANO);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < PISANO; i++)
    {
        dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD);
    }

    cout << dp[n % PISANO] << '\n';
    return 0;
}