#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define MAX 1000001
#define MOD 1000000009

long long dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    dp[1] = 1, dp[2] = 2, dp[3] = 4;

    int T; cin >> T;
    int M = 0;
    vector<int> com(T);
    for (int i = 0; i < T; i++) {
        cin >> com[i];
        M = max(com[i], M);
    }
    for (int i = 4; i <= M; i++) {
        dp[i] = (dp[i - 3] % MOD + dp[i - 2] % MOD + dp[i - 1] % MOD) % MOD;
    }

    for (int i = 0; i < T; i++) {
        cout << dp[com[i]]%MOD << '\n';
    }  
}
